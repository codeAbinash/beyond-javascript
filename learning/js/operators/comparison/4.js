"hey" == new String("hey") // true
new String("hey") == "hey" // true
new String("hey") == new String("hey") // false


"ok" == String("ok") // true
new String("ok") == String("ok") // true
"ok" == String(new String("ok")) // true