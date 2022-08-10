let str = "🤔✅"

str.length // 3
str.codePointAt(0) // 129300
str.codePointAt(1) // 56596
str.codePointAt(2) // 9989

str.codePointAt(20000) // undefined
str.codePointAt(-1) // undefined