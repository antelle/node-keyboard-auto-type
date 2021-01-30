{
  'targets': [
    {
      'target_name': 'keyboard-auto-type',
      'sources': [
        'src/addon.cpp',
        'src/auto-type.cpp',
        'src/key-code.cpp',
        'src/modifier.cpp',
        'keyboard-auto-type/keyboard-auto-type/src/auto-type.cpp',
        'keyboard-auto-type/keyboard-auto-type/src/utils.cpp',
      ],
      'include_dirs': [
        'keyboard-auto-type/keyboard-auto-type/include',
        'keyboard-auto-type/keyboard-auto-type/src',
        '<!(node -p \'require("node-addon-api").include_dir\')'
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'cflags': [ '-fno-exceptions' ],
      'cflags_cc': [ '-fno-exceptions' ],
      'conditions': [
        [ 'OS=="mac"', {
          'sources': [
            'keyboard-auto-type/keyboard-auto-type/src/darwin/auto-type.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/darwin/carbon-helpers.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/darwin/key-map.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/darwin/native-methods.mm',
          ],
          'xcode_settings': {
            'CLANG_CXX_LIBRARY': 'libc++',
            'MACOSX_DEPLOYMENT_TARGET': '10.7',
            'GCC_ENABLE_CPP_EXCEPTIONS': 'NO',
            'CLANG_CXX_LANGUAGE_STANDARD': 'gnu++17',
          },
          'link_settings': {
            'libraries': [
              "$(SDKROOT)/System/Library/Frameworks/AppKit.framework",
              "$(SDKROOT)/System/Library/Frameworks/Carbon.framework",
              "$(SDKROOT)/System/Library/Frameworks/CoreFoundation.framework",
              "$(SDKROOT)/System/Library/Frameworks/ScriptingBridge.framework",
            ]
          }
        }],
        [ 'OS=="win"', {
          'sources': [
            'keyboard-auto-type/keyboard-auto-type/src/win32/auto-type.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/win32/key-map.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/win32/winapi-tools.cpp',
          ],
          'msvs_settings': {
            'VCLinkerTool': {
              'AdditionalDependencies': ['Shlwapi.lib']
            },
            'AdditionalOptions': [ '-std:c++17' ]
          }
        }],
        [ 'OS=="linux"', {
          'cflags_cc': [
            '-std=c++17',
            '<!(pkg-config x11 --cflags-only-I)',
            '<!(pkg-config xtst --cflags-only-I)',
            '<!(pkg-config atspi-2 --cflags-only-I)',
            '<!(pkg-config glib-2.0 --cflags-only-I)',
            '<!(pkg-config gobject-2.0 --cflags-only-I)',
          ],
          'sources': [
            'keyboard-auto-type/keyboard-auto-type/src/linux/atspi-helpers.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/linux/auto-type.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/linux/key-map.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/linux/x11-helpers.cpp',
            'keyboard-auto-type/keyboard-auto-type/src/linux/x11-keysym-map.cpp',
          ],
          'libraries': [
            '<!(pkg-config x11 --libs)',
            '<!(pkg-config xtst --libs)',
            '<!(pkg-config atspi-2 --libs)',
            '<!(pkg-config glib-2.0 --libs)',
            '<!(pkg-config gobject-2.0 --libs)',
          ]
        }]
      ]
    }
  ]
}
