const arr = [1, 2, 3]
const bigArray = [-1, 0, arr, 4, 5]

const newArr = Array.from(bigArray)

console.log(newArr[2] === arr)