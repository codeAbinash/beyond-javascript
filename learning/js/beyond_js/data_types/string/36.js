let str1 = '\uFB00' // ﬀ
let str2 = '\u0066\u0066' // ff
console.log(str1 === str2) // false

str1 = str1.normalize('NFKD')
str2 = str2.normalize('NFKD')

console.log(str1 === str2) // false
console.log(str1) // ff
console.log(str2) // ff