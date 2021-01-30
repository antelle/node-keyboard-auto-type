# Node.js bindings for keyboard-auto-type

This project exposes [keyboard-auto-type](https://github.com/antelle/keyboard-auto-type) as Node.js API.

## Installation

```sh
npm i keyboard-auto-type
```

## Usage

You will find more docs in [keyboard-auto-type](https://github.com/antelle/keyboard-auto-type#usage) project. Here's how to use it in Node.js:

```js
const { AutoType, KeyCode, Modifier } = require('keyboard-auto-type');

const typer = new AutoType();
// get active process id
const pid = typer.activePid();
// get active window
const win = typer.activeWindow({ getWindowTitle: true, getBrowserUrl: true });
// show the window
typer.showWindow(win);

// type some text
typer.text('Hello');
// press shift+1
typer.keyPress(KeyCode.D1, Modifier.Shift);
```

## License

[MIT](LICENSE)
