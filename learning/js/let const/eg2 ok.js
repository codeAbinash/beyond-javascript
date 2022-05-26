function increment(num){
    // num is declared in this scope
    num = num + 1
    console.log(num)
}

increment(10)