let name = "Abinash"

switch (name) {
    case "Abinash": { // Different Scope
        let status = 10
        console.log("Fix that bug!")
        break
    }
    case "Tukai": { // Different Scope
        let status = 20
        console.log("Go to college")
        break
    }
}