const exp = /^[a-z0-9]+$/i;

exp.test('123abcAA'); // true
exp.test('1a2b5F'); // true
exp.test('1a2b5f_'); // false
exp.test('#5f_'); // false
