undefined == undefined // true
null == null // true

// Number type
NaN == NaN // false
NaN == 54 // false
15 == 15 // true
-958.55 == -958.55 // true
-0 == +0 // true
+0 == -0 // true


//String Type
"Hello" == "Hello" // true
"hello" == "Hello" // false


// Boolean type
true == true // true
false == false // true
true == false // false



let obj1 = {language : "JavaScript"}
let obj2 = {language : "JavaScript"}

obj1 == obj1 // true same object
obj1 == obj2 // false because objects are not same