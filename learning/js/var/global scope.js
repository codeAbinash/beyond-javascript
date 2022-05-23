var myName = "Abinash"
// This variable is Global Scoped  Variable
// Accessible everywhere in the program
console.log(myName) // accessible here

if(true){
    // accessible here too
    myName = "Pekachu"
    console.log(myName);
}

{
    // Here too
    console.log(myName);
}

function printName(){
    // Here too
    printName(myName)
}