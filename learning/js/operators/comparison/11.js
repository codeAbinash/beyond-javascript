undefined === undefined // true
null === null // true


//Number type
NaN === NaN // false
100 === 100 // true
+0 === -0 // true

"Hello" === "Hello" // true
101 === 101 // true

let obj1 = {name : "Pekachu"}
let obj2 = {name : "Pekachu"}

obj1 === obj2  // false, different object
obj1 === obj1  // true, same object

true === 1 // false
false === 0 // false