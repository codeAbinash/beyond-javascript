const str = 'I am a Good Boy.';
const reg = /[A-Z]/g;

let result = str.match(reg);

console.log(result); // [ 'I', 'G', 'B' ]
