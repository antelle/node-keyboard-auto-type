{
  "targets": [
    {
      "target_name": "keyboard-auto-type",
      "sources": [
        "src/addon.cpp",
        "src/auto-type.cpp",
        "src/key-code.cpp",
        "src/modifier.cpp",
        "keyboard-auto-type/keyboard-auto-type/src/auto-type.cpp",
        "keyboard-auto-type/keyboard-auto-type/src/utils.cpp",
        "keyboard-auto-type/keyboard-auto-type/src/darwin/auto-type.cpp",
        "keyboard-auto-type/keyboard-auto-type/src/darwin/carbon-helpers.cpp",
        "keyboard-auto-type/keyboard-auto-type/src/darwin/key-map.cpp",
        "keyboard-auto-type/keyboard-auto-type/src/darwin/native-methods.mm",
      ],
      "include_dirs": [
        "keyboard-auto-type/keyboard-auto-type/include",
        "keyboard-auto-type/keyboard-auto-type/src",
        "<!(node -p \"require('node-addon-api').include_dir\")"
      ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
      "link_settings": {
        "libraries": [
          "$(SDKROOT)/System/Library/Frameworks/AppKit.framework",
          "$(SDKROOT)/System/Library/Frameworks/Carbon.framework",
          "$(SDKROOT)/System/Library/Frameworks/CoreFoundation.framework",
          "$(SDKROOT)/System/Library/Frameworks/ScriptingBridge.framework",
        ],
      },
      "xcode_settings": {
        "CLANG_CXX_LIBRARY": "libc++",
        "MACOSX_DEPLOYMENT_TARGET": "10.14",
        "CLANG_CXX_LANGUAGE_STANDARD": "gnu++17"
      },
    }
  ]
}
