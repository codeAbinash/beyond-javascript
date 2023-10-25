let x = 456987456932158; // 15 digits
console.log(Number.isSafeInteger(x)); // true

let y = 9587456987454545; // 16 digits
console.log(Number.isSafeInteger(y)); // false
