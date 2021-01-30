#include "auto-type.h"

#include <string>

#include "keyboard-auto-type.h"

namespace kbd = keyboard_auto_type;

bool is_surrogate(char16_t uc) { return (uc - 0xd800U) < 2048u; }
bool is_high_surrogate(char16_t uc) { return (uc & 0xfffffc00U) == 0xd800; }
bool is_low_surrogate(char16_t uc) { return (uc & 0xfffffc00U) == 0xdc00; }
char32_t surrogate_to_utf32(char16_t high, char16_t low) { return (high << 10) + low - 0x35fdc00U; }

std::u32string to_str(Napi::String value) {
    auto u16str = value.Utf16Value();
    std::vector<char32_t> u32str;
    u32str.reserve(u16str.size() * 2 + 1);

    size_t i = 0;
    auto size = u16str.size();
    while (i < size) {
        auto uc = u16str[i++];
        if (!is_surrogate(uc)) {
            u32str.push_back(uc);
        } else if (is_high_surrogate(uc) && i < size && is_low_surrogate(u16str[i])) {
            u32str.push_back(surrogate_to_utf32(uc, u16str[i++]));
        }
    }

    return std::u32string(u32str.begin(), u32str.end());
}

class AutoType : public Napi::ObjectWrap<AutoType> {
  public:
    static Napi::Object init(Napi::Env env, Napi::Object exports);
    AutoType(const Napi::CallbackInfo &info);

  private:
    kbd::AutoType typer_;
    Napi::Value text(const Napi::CallbackInfo &info);
    Napi::Value key_press(const Napi::CallbackInfo &info);
    Napi::Value active_window(const Napi::CallbackInfo &info);
    Napi::Value active_pid(const Napi::CallbackInfo &info);
    Napi::Value show_window(const Napi::CallbackInfo &info);
};

Napi::Object AutoType::init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "AutoType",
                                      {
                                          InstanceMethod<&AutoType::text>("text"),
                                          InstanceMethod<&AutoType::key_press>("keyPress"),
                                          InstanceMethod<&AutoType::active_window>("activeWindow"),
                                          InstanceMethod<&AutoType::active_pid>("activePid"),
                                          InstanceMethod<&AutoType::show_window>("showWindow"),
                                      });

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(func);
    exports.Set("AutoType", func);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

AutoType::AutoType(const Napi::CallbackInfo &info) : Napi::ObjectWrap<AutoType>(info) {}

Napi::Value AutoType::text(const Napi::CallbackInfo &info) {
    if (!info.Length() || !info[0].IsString()) {
        Napi::TypeError::New(info.Env(), "Text is not a string").ThrowAsJavaScriptException();
        return info.Env().Undefined();
    }

    auto text = to_str(info[0].ToString());
    typer_.text(text);

    return info.Env().Undefined();
}

Napi::Value AutoType::key_press(const Napi::CallbackInfo &info) {
    if (!info.Length() || !info[0].IsNumber()) {
        Napi::TypeError::New(info.Env(), "Empty key code").ThrowAsJavaScriptException();
        return info.Env().Undefined();
    }

    auto code = info[0].ToNumber().Int32Value();
    if (code <= 0 && code >= static_cast<int>(kbd::KeyCode::KeyCodeCount)) {
        Napi::RangeError::New(info.Env(), "Bad key code").ThrowAsJavaScriptException();
        return info.Env().Undefined();
    }

    auto modifier = kbd::Modifier::None;
    if (info.Length() > 1 && info[1].IsNumber()) {
        modifier = static_cast<kbd::Modifier>(info[1].ToNumber().Uint32Value());
    }

    typer_.key_press(static_cast<kbd::KeyCode>(code), modifier);

    return info.Env().Undefined();
}

Napi::Value AutoType::active_pid(const Napi::CallbackInfo &info) {
    auto pid = typer_.active_pid();
    return Napi::Number::New(info.Env(), pid);
}

Napi::Value AutoType::active_window(const Napi::CallbackInfo &info) {
    auto env = info.Env();

    kbd::ActiveWindowArgs args{};

    if (info.Length() && info[0].IsObject()) {
        auto arg = info[0].ToObject();
        if (arg.Get("getWindowTitle").ToBoolean()) {
            args.get_window_title = true;
        }
        if (arg.Get("getBrowserUrl").ToBoolean()) {
            args.get_browser_url = true;
        }
    }

    auto win = typer_.active_window(args);

    auto obj = Napi::Object::New(env);

    if (win.pid) {
        obj.Set("pid", Napi::Number::New(env, win.pid));
    }
    if (win.window_id) {
        obj.Set("windowId", Napi::Number::New(env, win.window_id));
    }
    if (!win.app_name.empty()) {
        obj.Set("appName", Napi::String::From(env, win.app_name));
    }
    if (!win.title.empty()) {
        obj.Set("title", Napi::String::From(env, win.title));
    }
    if (!win.url.empty()) {
        obj.Set("url", Napi::String::From(env, win.url));
    }

    return obj;
}

Napi::Value AutoType::show_window(const Napi::CallbackInfo &info) {
    if (!info.Length() || !info[0].IsObject()) {
        Napi::TypeError::New(info.Env(), "Empty window").ThrowAsJavaScriptException();
        return info.Env().Undefined();
    }

    auto arg = info[0].ToObject();

    kbd::AppWindow win{};
    win.pid = arg.Get("pid").ToNumber().Int32Value();
    win.window_id = arg.Get("windowId").ToNumber().Uint32Value();

    auto shown = typer_.show_window(win);

    return Napi::Boolean::New(info.Env(), shown);
}

void export_auto_type(Napi::Env env, Napi::Object exports) { AutoType::init(env, exports); }