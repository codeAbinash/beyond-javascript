Number.parseInt() // NaN
Number.parseInt("123455") // 123456
Number.parseInt("123.456") // 123
Number.parseInt("-123.456") // -123
Number.parseInt("123ABCD") // 123
Number.parseInt("ABinash") // NaN
Number.parseInt("") // NaN
Number.parseInt(" ") // NaN
Number.parseInt([]) // NaN
Number.parseInt([10]) // 10
Number.parseInt([10, 20]) // 10
Number.parseInt({}) // NaN
Number.parseInt("10 kg") // 10
Number.parseInt("kg 10") // NaN