function myFunction() {
  a = 10; // Global variable `a`
}
myFunction();

// A can be accessed globally outside of `myFunction()` function
console.log(a); // 10
