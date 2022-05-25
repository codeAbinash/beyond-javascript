{
    // TDZ of "a" starts from here
    console.log("Hello") // TDZ of "a"
    // TDZ of "a"
    if(true)   // TDZ of "a"
        console.log("Abinash") // TDZ of "a"
    // TDZ of "a"    
    let a // TDZ ends here
    a = 100
    console.log(a)
}