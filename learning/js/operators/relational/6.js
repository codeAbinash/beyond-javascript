const num = new Number(500)
num instanceof Number // true

const date = new Date()
date instanceof Date // true

({} instanceof Object) // true


const a = 5 // primitive type
const b = new Number(5) // Number type


a instanceof Number // false
b instanceof Number // true
b instanceof Object // true