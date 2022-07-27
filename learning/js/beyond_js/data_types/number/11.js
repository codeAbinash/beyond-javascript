console.log(Number()) // 0
console.log(Number(100)) // 100
console.log(Number('200')) // 200
console.log(Number('200R')) // NaN
console.log(Number("Hello")) // NaN

console.log(Number('')) // 0
console.log(Number(' ')) // 0

console.log(Number(undefined)) // NaN
console.log(Number(null)) // 0

console.log(Number('0b10')) // 2
console.log(Number('0x10')) // 16
console.log(Number('0o10')) // 8

console.log(Number([])) // 0
console.log(Number({})) // NaN
console.log(Number([10])) // 10
console.log(Number([1,2,3])) // NaN

console.log(Number('Infinity')) // Infinity
console.log(Number('-Infinity')) // -Infinity