#include "addon-modifier.h"

#include "keyboard-auto-type.h"

namespace kbd = keyboard_auto_type;

void export_modifier(Napi::Env env, Napi::Object exports) {
    auto mod = Napi::Object::New(env);

    using T = std::underlying_type<kbd::Modifier>::type;

    mod.Set("None", Napi::Number::New(env, static_cast<T>(kbd::Modifier::None)));

    mod.Set("Ctrl", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Ctrl)));
    mod.Set("Control", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Control)));
    mod.Set("RightCtrl", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightCtrl)));
    mod.Set("RightControl", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightControl)));
    mod.Set("LeftCtrl", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftCtrl)));
    mod.Set("LeftControl", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftControl)));

    mod.Set("Alt", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Alt)));
    mod.Set("Option", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Option)));
    mod.Set("RightAlt", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightAlt)));
    mod.Set("RightOption", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightOption)));
    mod.Set("LeftAlt", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftAlt)));
    mod.Set("LeftOption", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftOption)));

    mod.Set("Shift", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Shift)));
    mod.Set("RightShift", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightShift)));
    mod.Set("LeftShift", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftShift)));

    mod.Set("Meta", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Meta)));
    mod.Set("Command", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Command)));
    mod.Set("Win", Napi::Number::New(env, static_cast<T>(kbd::Modifier::Win)));
    mod.Set("RightMeta", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightMeta)));
    mod.Set("RightCommand", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightCommand)));
    mod.Set("RightWin", Napi::Number::New(env, static_cast<T>(kbd::Modifier::RightWin)));
    mod.Set("LeftMeta", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftMeta)));
    mod.Set("LeftCommand", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftCommand)));
    mod.Set("LeftWin", Napi::Number::New(env, static_cast<T>(kbd::Modifier::LeftWin)));

    exports.Set("Modifier", mod);
}