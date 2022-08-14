'A'.localeCompare('A') // 0
'a'.localeCompare('b') // -1
'c'.localeCompare('a') //  1

"hello".localeCompare("world") // -1
"Hello".localeCompare("Hello") // 0

let str1 = 'réservé'
let str2 = 'RESERVE'

str1.localeCompare(str2) // 1
str1.localeCompare(str2, 'en', { sensitivity: 'base' }) // 0