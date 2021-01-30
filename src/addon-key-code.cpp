#include "addon-key-code.h"

#include "keyboard-auto-type.h"

namespace kbd = keyboard_auto_type;

void export_key_code(Napi::Env env, Napi::Object exports) {
    auto mod = Napi::Object::New(env);

    using T = std::underlying_type<kbd::KeyCode>::type;

    mod.Set("D0", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D0)));
    mod.Set("D1", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D1)));
    mod.Set("D2", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D2)));
    mod.Set("D3", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D3)));
    mod.Set("D4", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D4)));
    mod.Set("D5", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D5)));
    mod.Set("D6", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D6)));
    mod.Set("D7", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D7)));
    mod.Set("D8", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D8)));
    mod.Set("D9", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D9)));

    mod.Set("A", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::A)));
    mod.Set("B", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::B)));
    mod.Set("C", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::C)));
    mod.Set("D", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::D)));
    mod.Set("E", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::E)));
    mod.Set("F", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F)));
    mod.Set("G", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::G)));
    mod.Set("H", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::H)));
    mod.Set("I", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::I)));
    mod.Set("J", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::J)));
    mod.Set("K", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::K)));
    mod.Set("L", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::L)));
    mod.Set("M", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::M)));
    mod.Set("N", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::N)));
    mod.Set("O", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::O)));
    mod.Set("P", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::P)));
    mod.Set("Q", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Q)));
    mod.Set("R", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::R)));
    mod.Set("S", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::S)));
    mod.Set("T", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::T)));
    mod.Set("U", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::U)));
    mod.Set("V", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::V)));
    mod.Set("W", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::W)));
    mod.Set("X", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::X)));
    mod.Set("Y", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Y)));
    mod.Set("Z", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Z)));

    mod.Set("F1", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F1)));
    mod.Set("F2", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F2)));
    mod.Set("F3", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F3)));
    mod.Set("F4", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F4)));
    mod.Set("F5", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F5)));
    mod.Set("F6", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F6)));
    mod.Set("F7", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F7)));
    mod.Set("F8", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F8)));
    mod.Set("F9", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F9)));
    mod.Set("F10", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F10)));
    mod.Set("F11", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F11)));
    mod.Set("F12", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F12)));
    mod.Set("F13", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F13)));
    mod.Set("F14", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F14)));
    mod.Set("F15", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F15)));
    mod.Set("F16", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F16)));
    mod.Set("F17", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F17)));
    mod.Set("F18", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F18)));
    mod.Set("F19", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F19)));
    mod.Set("F20", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F20)));
    mod.Set("F21", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F21)));
    mod.Set("F22", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F22)));
    mod.Set("F23", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F23)));
    mod.Set("F24", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::F24)));

    mod.Set("Keypad0", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad0)));
    mod.Set("Keypad1", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad1)));
    mod.Set("Keypad2", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad2)));
    mod.Set("Keypad3", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad3)));
    mod.Set("Keypad4", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad4)));
    mod.Set("Keypad5", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad5)));
    mod.Set("Keypad6", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad6)));
    mod.Set("Keypad7", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad7)));
    mod.Set("Keypad8", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad8)));
    mod.Set("Keypad9", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Keypad9)));

    mod.Set("KeypadClear", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadClear)));
    mod.Set("KeypadDecimal", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadDecimal)));
    mod.Set("KeypadDivide", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadDivide)));
    mod.Set("KeypadEnter", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadEnter)));
    mod.Set("KeypadEquals", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadEquals)));
    mod.Set("KeypadMinus", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadMinus)));
    mod.Set("KeypadMultiply", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadMultiply)));
    mod.Set("KeypadPlus", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::KeypadPlus)));

    mod.Set("Backslash", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Backslash)));
    mod.Set("Comma", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Comma)));
    mod.Set("Equal", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Equal)));
    mod.Set("Grave", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Grave)));
    mod.Set("LeftBracket", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::LeftBracket)));
    mod.Set("Minus", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Minus)));
    mod.Set("Period", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Period)));
    mod.Set("Quote", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Quote)));
    mod.Set("RightBracket", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightBracket)));
    mod.Set("Semicolon", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Semicolon)));
    mod.Set("Slash", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Slash)));

    mod.Set("Meta", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Meta)));
    mod.Set("Command", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Command)));
    mod.Set("Win", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Win)));
    mod.Set("Ctrl", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Ctrl)));
    mod.Set("Control", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Control)));
    mod.Set("Function", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Function)));
    mod.Set("Alt", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Alt)));
    mod.Set("Option", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Option)));
    mod.Set("Shift", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Shift)));
    mod.Set("RightMeta", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightMeta)));
    mod.Set("RightCommand", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightCommand)));
    mod.Set("RightWin", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightWin)));
    mod.Set("RightCtrl", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightCtrl)));
    mod.Set("RightControl", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightControl)));
    mod.Set("RightAlt", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightAlt)));
    mod.Set("RightOption", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightOption)));
    mod.Set("RightShift", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightShift)));
    mod.Set("CapsLock", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::CapsLock)));
    mod.Set("NumLock", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::NumLock)));
    mod.Set("ScrollLock", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::ScrollLock)));

    mod.Set("DownArrow", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::DownArrow)));
    mod.Set("LeftArrow", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::LeftArrow)));
    mod.Set("RightArrow", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::RightArrow)));
    mod.Set("UpArrow", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::UpArrow)));

    mod.Set("End", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::End)));
    mod.Set("Home", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Home)));
    mod.Set("PageDown", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::PageDown)));
    mod.Set("PageUp", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::PageUp)));

    mod.Set("ContextMenu", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::ContextMenu)));
    mod.Set("BackwardDelete", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::BackwardDelete)));
    mod.Set("Backspace", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Backspace)));
    mod.Set("Escape", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Escape)));
    mod.Set("ForwardDelete", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::ForwardDelete)));
    mod.Set("Help", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Help)));
    mod.Set("Mute", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Mute)));
    mod.Set("PrintScreen", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::PrintScreen)));
    mod.Set("Snapshot", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Snapshot)));
    mod.Set("Return", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Return)));
    mod.Set("Enter", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Enter)));
    mod.Set("Space", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Space)));
    mod.Set("Tab", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Tab)));
    mod.Set("VolumeDown", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::VolumeDown)));
    mod.Set("VolumeUp", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::VolumeUp)));
    mod.Set("Pause", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Pause)));
    mod.Set("Insert", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Insert)));
    mod.Set("Sleep", Napi::Number::New(env, static_cast<T>(kbd::KeyCode::Sleep)));

    exports.Set("KeyCode", mod);
}