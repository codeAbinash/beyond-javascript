let str = 'This is JavaScript';

str.substring(); // 'This is JavaScript' , full string
str.substring(8); // 'JavaScript', using one argument , from index 8 to end
str.substring(str.length - 6); // 'Script', last 6 characters
str.substring(12, 18); // 'Script', excluding end index
str.substring(18, 12); // 'Script', automatically detect start and end index
str.substring(10, 10); // '', same index, empty string
str.substring(-5, 4); // 'This', -5 is less than 0, treated as 0
str.substring(-5, 4000); // 'This', 4000 is greater than str.length, treated as str.length
