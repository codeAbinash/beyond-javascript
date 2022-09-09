const str = 'hello World, hello Abinash'
const exp = /hello/g
let arr

while ((arr = exp.exec(str)) !== null)
    console.log(arr[0], 'found at index', exp.lastIndex)