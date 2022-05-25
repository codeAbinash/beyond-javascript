let x = 10
if (x == 10) {
    let x = 100
    // It is ok because
    //declaring x, not in the same scope
    console.log(x)
}