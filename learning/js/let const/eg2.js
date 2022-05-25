function increment(num){
    // Number is declared in this scope

    let num = num + 1
    // Declaring again will cause SyntaxError
    console.log(num)
}

increment(10)