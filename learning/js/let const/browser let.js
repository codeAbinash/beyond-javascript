//temporal dead zone of variable "a"
console.log("start")

let a // TDZ of 'a' ends here

a = 10

console.log(a)
console.log("end")