1 != 5; // true
1 != 1; // false
'hello' != 'hey'; // true

5 != '5'; // false
0 != null; // true
0 != undefined; // true
null != undefined; // false

const string1 = 'hello';
const string2 = new String('hello');
const string3 = String('hello');

string1 != string2; // false
string1 != string3; // false
string2 != string3; // false
