const arr = new Array(2 ** 32 - 1); // Ok
arr.push('An element'); // RangeError: Invalid array length
