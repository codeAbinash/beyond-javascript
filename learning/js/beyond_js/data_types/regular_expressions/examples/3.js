const exp = /^#?([0-9a-fA-F]{3}|[0-9a-fA-F]{6})$/

exp.test('#fff') // true
exp.test('#f598fa') // true
exp.test('f45f54') // true
exp.test('7af') // true
exp.test('hg') // false
exp.test('9854') // false