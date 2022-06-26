const something = "" 
// `something` can be any value that can be converted to a number

+Infinity > something // true
something > +Infinity // false

-Infinity > something // false
something > -Infinity //true

-Infinity > +Infinity // false
+Infinity > -Infinity // true