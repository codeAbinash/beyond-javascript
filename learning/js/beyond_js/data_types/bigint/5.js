let num = BigInt(Number.MAX_SAFE_INTEGER);
let large = num ** num; // too long number
// will cause RangeError
console.log(large);
