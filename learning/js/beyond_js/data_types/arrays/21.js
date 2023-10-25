const arr = ['a', 'b', 'c'];
arr.length; // 3
arr.length = 10;
console.log(arr); // [ 'a', 'b', 'c', <7 empty items> ]

arr.length = 2;
console.log(arr); // [ 'a', 'b' ]
