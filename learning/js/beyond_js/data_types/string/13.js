let str = 'JavaScript';
console.log(str.at(0)); // 'J'
console.log(str.at(10000)); // undefined

console.log(str.at(5)); // 'c'
console.log(str.at(-1)); // 't', the last character
console.log(str.at(-3)); // 'i', at index 3 from the end of the string
