let gotTheNumber = false
let number

while (!gotTheNumber) {
    number = Math.random()
    if (number > 0.7) {
        gotTheNumber = true
        console.log("We got the number")
    }
    console.log(number)
}