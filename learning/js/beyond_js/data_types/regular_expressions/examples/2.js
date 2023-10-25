const exp = /[0-9a-fA-F]+$/;

exp.test('fff'); // true
exp.test('1ca5c'); // true
exp.test('FA'); // true
exp.test('98455'); // true

exp.test('ggg'); // false
exp.test('adc51v'); // false
