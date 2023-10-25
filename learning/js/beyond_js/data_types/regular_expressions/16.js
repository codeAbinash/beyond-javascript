const str = 'ababab';
const exp = /ab/g;

const matches = [...str.matchAll(exp)];
console.log(matches); // ['ab', 'ab', 'ab']
