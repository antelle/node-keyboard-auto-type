#include <napi.h>

#include "auto-type.h"
#include "key-code.h"
#include "keyboard-auto-type.h"
#include "modifier.h"

namespace kbd = keyboard_auto_type;

Napi::Object init(Napi::Env env, Napi::Object exports) {
    export_modifier(env, exports);
    export_key_code(env, exports);
    export_auto_type(env, exports);
    return exports;
}

NODE_API_MODULE(keyboard_auto_type, init)
