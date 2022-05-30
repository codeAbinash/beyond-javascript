typeof 5 // number
typeof -21 // number
typeof 2.655 // number
typeof "Hello World" // string
typeof 'Okk' // string
typeof true // boolean
typeof false // boolean
typeof unDeclaredVariable // undefined

let undefinedVariable
typeof undefinedVariable // undefined

typeof undefined // undefined
typeof null // object
typeof 415413541654645156n // bigint
typeof Symbol("mySymbol") // symbol
typeof {name : "Pekachu"} // Object
typeof NaN // number
typeof Infinity // number
typeof (typeof 10) // string,
// because (typeof 10) is a string
typeof [1,2,3,4,5,6] // object
typeof [1,2,3,4,5,6] // object
typeof Number // function
typeof Number(10) // Number
typeof new Number(100) // object
typeof Date // function
typeof new Date() // object


function myFunction(){
    console.log("myFunction")
}
typeof myFunction // function


class myClass{}
typeof myClass // function


function numberReturn(){
    return 200
}
typeof numberReturn() // number 


function stringReturn(){
    return "Happy"
}
typeof stringReturn() // string