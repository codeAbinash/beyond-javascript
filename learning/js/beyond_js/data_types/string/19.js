"Hello World".endsWith("World") // true
"Hello World".endsWith("JS") // false
"Hello World".endsWith("") // true
"a".endsWith("a") // true
"a ".endsWith("a") // false, extra space

"JavaScript JS".endsWith("Script",10) // true
// `10` is passed as 2nd argument. 
// It is used as the length of the string.