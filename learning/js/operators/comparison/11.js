undefined === undefined; // true
null === null; // true

//Number type
NaN === NaN; // false
(100 ===
  100 + // true
    0) ===
  -0; // true

'1,2,3' === [1, 2, 3]; // false

'Hello' === 'Hello'; // true
'Hello' === new String('Hello'); // false
'Hello' === String('Hello'); // true
String('Hello') === new String('Hello'); // false

101 === 101; // true
const obj1 = { name: 'Pekachu' };
const obj2 = { name: 'Pekachu' };

obj1 === obj2; // false, different object
obj1 === obj1; // true, same object

true === 1; // false
false === 0; // false
