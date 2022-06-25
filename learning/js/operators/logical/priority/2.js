let value = false || "hmm" && !"Ok"
console.log(value)

// Steps
// false || "hmm" && !"Ok"
// false || "hmm" && false
// false || false
// false