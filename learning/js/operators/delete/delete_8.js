function Hello(){
    console.log("My Function")
}

Hello.prototype.number = 100

let hi = new Hello()
console.log(hi.number) // 100

delete hi.number // deleting number // returns true

console.log(hi.number)
// 100 🤨 But why? We already deleted it