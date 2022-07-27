Number.parseFloat() // NaN
Number.parseFloat('') // NaN
Number.parseFloat(' ') // NaN
Number.parseFloat('123') // 123
Number.parseFloat('123.45') // 123.45
Number.parseFloat('-123.45Ok') // -123.45
Number.parseFloat([10.23]) // 10.23
Number.parseFloat([10.23, 11.55]) // 10.23
Number.parseFloat([10.23, 11.55]) // 10.23
Number.parseFloat("5 cm") // 5
Number.parseFloat("5.23 cm") // 5
Number.parseFloat("cm2.33") // NaN