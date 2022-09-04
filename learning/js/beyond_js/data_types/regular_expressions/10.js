let str = 'In this string we will find "string"'
let exp = /string/g


exp.lastIndex // 0
exp.test(str) // true

exp.lastIndex // 14
exp.test(str) // true

exp.lastIndex // 35
exp.test(str) // false

exp.lastIndex // 0