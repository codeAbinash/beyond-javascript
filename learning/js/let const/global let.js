// using let
let myName = 'Abinash';
// here "this" refers to the global object (for browsers, window)
console.log(this.myName); // undefined

// Using var
var yourName = 'John'; // attached to the global object
console.log(this.yourName); // "John"
