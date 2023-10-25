100 <= 100; // true
40 <= 3; // true
3n <= 3; // true

10 <= '10'; // true
'Pekachu' <= 'Pekachu'; // true
'Hello World' <= 'Hello'; // false
'hey' <= 10; // false
10 <= 'hey'; // false

NaN <= NaN; // false
undefined <= undefined; // false
null <= 0; // true
null <= 1; // true
