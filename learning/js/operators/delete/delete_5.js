let student = {
    name : "Ananta",
    age : 18
}

Object.defineProperty(student, "name" , {configurable : false})
// Making the "name" property of "student" non configurable

console.log(delete student.name)
console.log(student)