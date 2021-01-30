const { AutoType, KeyCode, Modifier } = require('.');

const typer = new AutoType();

const pid = typer.activePid();
const win = typer.activeWindow({ getWindowTitle: true, getBrowserUrl: true });

console.log('Active pid:', pid);
console.log('Active window:', win);

typer.text('Hello');
typer.keyPress(KeyCode.D1, Modifier.Shift);
