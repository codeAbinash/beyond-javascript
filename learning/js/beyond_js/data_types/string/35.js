let str = 'hey';

str.repeat(5); // 'heyheyheyheyhey'
str.repeat(5.9); // 'heyheyheyheyhey', converted to integer (5)
str.repeat(Infinity); // RangeError: Invalid count value
str.repeat(-5); // RangeError: Invalid count value
