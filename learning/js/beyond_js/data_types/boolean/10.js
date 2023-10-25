let x = new Boolean(false);

if (x.valueOf()) console.log('Hello World');
// because primitive false is falsy
else console.log('valueOf() returns the primitive value');
