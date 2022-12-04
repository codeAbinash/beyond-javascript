const numbers = [1, 3, 5, 7, 9]
const newNumbers = Array.from(numbers, multiply2)
console.log(newNumbers) // [ 2, 6, 10, 14, 18 ]

function multiply2(num) {
    return num * 2
}