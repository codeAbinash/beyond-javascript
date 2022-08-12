let str = '   hey there    '
str.trim() // 'hey there'

str = '  \t  Hello      World\n   \t   '
str.trim() // 'Hello      World

str = "no whitespace"
str.trim() // 'no whitespace'