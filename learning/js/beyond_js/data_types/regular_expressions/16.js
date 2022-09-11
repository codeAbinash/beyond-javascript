let str = 'ababab'
let exp = /ab/g

let matches = [...str.matchAll(exp)]
console.log(matches) // ['ab', 'ab', 'ab']