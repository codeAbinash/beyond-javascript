const exp = /<([a-z]+.*)(\s.*)*>.*<\/\1>/i;

exp.test('<p>Hello World</p>'); // true
exp.test('<h1></h1>'); // true
exp.test('<h1 style="color:red"></h1>'); // true
exp.test('<input style="color:red" disabled></input>'); // true
exp.test('<p>Hello World'); // false
exp.test('Hi Abinash'); // false
