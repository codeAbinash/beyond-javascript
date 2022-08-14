let str = "This is JavaScript Language"
str.slice() // This is JavaScript Language
str.slice(8) // 'JavaScript Language', From index 8 to end
str.slice(8, 18) // 'JavaScript', end index exclusive

str.slice(50000) // '', empty string
str.slice(8, 10000) // 'JavaScript Language'
str.slice(80000, 10) // '', empty string

str.slice(5, -9) // 'is JavaScript', from 5 to 9th index from end