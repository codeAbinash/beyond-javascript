var num = 1;
// Global Scope

function writeNumber() {
  // Function scope
  var num = 2;
  console.log(num);
}
writeNumber();

// Global Scope
console.log(num);
