const exp = /^[A-Z]/;

exp.test('Hello'); // true
exp.test('hello'); // false
exp.test('hello Abinash'); // false
