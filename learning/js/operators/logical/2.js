// All these values are truthy

true;

1;
5413;
10n;

('Hello');
(' '); // whitespace
('false');

{
} // empty object
[][10]; // empty array
{
  data: 55;
} // Any object

new Number(); // Number object
new Boolean(true); // Boolean object
new Boolean(false); // Boolean Object
new String(); // String Object

Infinity - Infinity;
