let str = 'I am Abinash'

str.includes('Abinash') // true
str.includes('He') // false
str.includes('') // true

str.includes('I', 5) // false, starts searching from index 5