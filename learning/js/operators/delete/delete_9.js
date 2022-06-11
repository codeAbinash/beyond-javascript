function Hello(){
    console.log("My Function")
}

Hello.prototype.number = 100

console.log(Hello.prototype.number) // 100

delete Hello.prototype.number // returns true

console.log(Hello.prototype.number) // undefined