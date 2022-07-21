let x = 10
{
    console.log("Hello World")
    {
        // x is not defined in this scope
        console.log(x)
        // but x is accessible in this scope
    }
}