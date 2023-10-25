const arr1 = new Array(-10); // RangeError: Invalid array length
const arr2 = new Array(5.2); // RangeError: Invalid array length
const arr3 = new Array(Infinity); // RangeError: Invalid array length
