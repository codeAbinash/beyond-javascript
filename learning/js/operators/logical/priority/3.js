const value = (false || 'hmm') && !'Ok';
console.log(value);

// Steps
// (false || "hmm") && !"Ok"
// "hmm" && !"Ok"
// "hmm" && false
// false
