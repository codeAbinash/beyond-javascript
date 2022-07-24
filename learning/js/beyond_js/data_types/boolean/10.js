let x = new Boolean(false)

if (x.valueOf())
    console.log("Hello World")
else // because primitive false is falsy
    console.log("valueOf() returns the primitive value")