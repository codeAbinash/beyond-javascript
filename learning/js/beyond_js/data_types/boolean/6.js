Boolean() // false
Boolean(false) // false
Boolean("") // false
Boolean(0) // false

Boolean(true) // true
Boolean(" ") // true
Boolean({}) // true // because objects are considered as true
Boolean({Name : "Abinash"}) // true
Boolean([]) // true
Boolean(-Infinity) // true
Boolean(+Infinity) // true
Boolean("true") // true
Boolean("false") // true