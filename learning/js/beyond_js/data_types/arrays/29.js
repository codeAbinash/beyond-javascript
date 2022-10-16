const colors = ['red', 'black', 'green', 'pink', 'blue', 'green']

console.log(colors.lastIndexOf('green')) // 5
console.log(colors.lastIndexOf('crimson')) // -1


console.log(colors.lastIndexOf('green', 3))  // 2
// Starts searching from index 3, backward