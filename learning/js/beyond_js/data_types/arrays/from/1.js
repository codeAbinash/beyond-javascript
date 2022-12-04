// From Array
const myArray = [1, 5, 9, 9, 8, 7, 4, 5]
const newArray = Array.from(myArray) // Copies myArray to newArray
console.log(myArray === newArray) // false, because of shallow copying 


// From String
const myName = 'Abinash'
console.log(Array.from(myName))
// ['A', 'b', 'i','n', 'a', 's','h']


// From Array-like objects
const myNumbers = {
    0: 'Hey',
    3: 'Wow',
    1: 'Done',
    2: 'Good',
    length: 4
}
console.log(Array.from(myNumbers)) // [ 'Hey', 'Done', 'Good', 'Wow' ]


// From set
const mySet = new Set([1, 4, 5, 6, 0])
console.log(Array.from(mySet)) // [ 1, 4, 5, 6, 0 ]


// From map
const myMap = new Map([
    [4, 'Ok'],
    [2, 'Think'],
    [1, 'Great']
])
console.log(Array.from(myMap)) // [ [ 4, 'Ok' ], [ 2, 'Think' ], [ 1, 'Great' ] ] 


// For normal object
const obj = {
    'name': 'Abinash',
    'Language': 'JavaScript'
}

console.log(Array.from(obj))