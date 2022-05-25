// using let
let myName = "Abinash"
// here "this" refers to the global object (window)
console.log(this.myName) // Undefined


// Using var
var yourName = "John" // attached to the global object
console.log(this.yourName) // "John"