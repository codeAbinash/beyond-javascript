const USER = "Abinash"
const PASS = "1234"

if (USER) {
    console.log("Hello " + USER)
    if (PASS) {
        console.log("You have a password")
        console.log("The password is : " + PASS)
    }
    else
        console.log("You Must set a password!")
}
else
    console.log("Hello Anonymous")