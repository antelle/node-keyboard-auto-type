#include <napi.h>

#include "addon-auto-type.h"
#include "addon-key-code.h"
#include "addon-modifier.h"
#include "keyboard-auto-type.h"

namespace kbd = keyboard_auto_type;

Napi::Object init(Napi::Env env, Napi::Object exports) {
    export_modifier(env, exports);
    export_key_code(env, exports);
    export_auto_type(env, exports);
    return exports;
}

NODE_API_MODULE(keyboard_auto_type, init)
