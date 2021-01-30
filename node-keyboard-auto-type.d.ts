/// <reference types="node" />

declare namespace NodeKeyboardAutoType {
    enum KeyCode {
        D0,
        D1,
        D2,
        D3,
        D4,
        D5,
        D6,
        D7,
        D8,
        D9,

        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,

        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F13,
        F14,
        F15,
        F16,
        F17,
        F18,
        F19,
        F20,
        F21,
        F22,
        F23,
        F24,

        Keypad0,
        Keypad1,
        Keypad2,
        Keypad3,
        Keypad4,
        Keypad5,
        Keypad6,
        Keypad7,
        Keypad8,
        Keypad9,

        KeypadClear,
        KeypadDecimal,
        KeypadDivide,
        KeypadEnter,
        KeypadEquals,
        KeypadMinus,
        KeypadMultiply,
        KeypadPlus,

        // others
        Backslash,
        Comma,
        Equal,
        Grave,
        LeftBracket,
        Minus,
        Period,
        Quote,
        RightBracket,
        Semicolon,
        Slash,

        Meta,
        Command,
        Win,
        Ctrl,
        Control,
        Function,
        Alt,
        Option,
        Shift,
        RightMeta,
        RightCommand,
        RightWin,
        RightCtrl,
        RightControl,
        RightAlt,
        RightOption,
        RightShift,
        CapsLock,
        NumLock,
        ScrollLock,

        DownArrow,
        LeftArrow,
        RightArrow,
        UpArrow,

        End,
        Home,
        PageDown,
        PageUp,

        ContextMenu,
        BackwardDelete,
        Backspace,
        Escape,
        ForwardDelete,
        Help,
        Mute,
        PrintScreen,
        Snapshot,
        Return,
        Enter,
        Space,
        Tab,
        VolumeDown,
        VolumeUp,
        Pause,
        Insert,
        Sleep
    }

    enum Modifier {
        None,

        Ctrl,
        Control,
        RightCtrl,
        RightControl,
        LeftCtrl,
        LeftControl,

        Alt,
        Option,
        RightAlt,
        RightOption,
        LeftAlt,
        LeftOption,

        Shift,
        RightShift,
        LeftShift,

        Meta,
        Command,
        Win,
        RightMeta,
        RightCommand,
        RightWin,
        LeftMeta,
        LeftCommand,
        LeftWin
    }

    interface AppWindow {
        pid?: number;
        windowId?: number;
        title?: string;
        appName?: string;
        url?: string;
    }

    class AutoType {
        text(str: string): void;
        keyPress(code: KeyCode, modifier?: Modifier): void;
        shortcut(code: KeyCode): void;
        keyMoveWithCode(down: boolean, code: KeyCode, modifier?: Modifier): void;
        keyMoveWithModifier(down: boolean, modifier: Modifier): void;
        keyMoveWithCharacter(
            down: boolean,
            character?: string,
            code?: number,
            modifier?: Modifier
        ): void;
        ensureModifierNotPressed(): void;
        setAutoUnpressModifiers(autoUnpressModifiers: boolean): void;
        setCheckPressedModifiers(checkPressedModifiers: boolean): void;

        activePid(): number;
        activeWindow(): AppWindow;
        showWindow(win: AppWindow): boolean;
    }
}

export = NodeKeyboardAutoType;
