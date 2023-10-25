const obj1 = {
  name: 'Abinash',
  age: 20,
};

const obj2 = {
  language: 'JavaScript',
};

Object.setPrototypeOf(obj2, obj1); // setting prototype

console.log('name' in obj2); // true
console.log(obj2.name); // 'Abinash'
