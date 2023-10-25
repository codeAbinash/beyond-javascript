const laptop = {
  price: 200,
  ram: '8GB',
  storage: '1TB',
};

console.log('price' in laptop); // true
delete laptop.price;
console.log('price' in laptop); // false
