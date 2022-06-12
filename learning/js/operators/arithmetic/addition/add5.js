let x = 10
let y = -5
let z = "JavaScript"

+x // 10
+y // -5
+z // NaN

+true// 1
+false // 0

+"100 Apples" // NaN
+"" // 0
+"100" // 100

+{obj : "Object"} // NaN, Object

+[] // 0, Empty Array
+[1,2,3] // NaN, Non Empty Array
+[88] // 88, Array With Single Element
+[""] // 0
+["99"] // 99
+[[["99"]]] // 99

+undefined // NaN
+null // 0

+(new Number()) // 0
+(new String()) // 0
+(new Object()) // NaN

+0x55554 // 349524, converts from hexadecimal