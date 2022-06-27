function celsiusToFahrenheit(celsius){
    let fahrenheit = (celsius * 9/5) + 32
    return fahrenheit
}

const TEMP1 = celsiusToFahrenheit(0)
const TEMP2 = celsiusToFahrenheit(88)

console.log("F : " + TEMP1 + ", " + TEMP2)