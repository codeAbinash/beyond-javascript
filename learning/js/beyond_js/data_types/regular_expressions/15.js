const str = 'NaN, -Infinity, +Infinity, 80, +80 -80, null etc.'

str.match(null) // ['null']
str.match(NaN) // ['NaN']
str.match(Infinity) // ['Infinity']
str.match(-Infinity) // ['-Infinity']
str.match(+Infinity) // ['Infinity']
str.match(80) // ['80']
str.match(-80) // ['80']
str.match(+80) // ['80']