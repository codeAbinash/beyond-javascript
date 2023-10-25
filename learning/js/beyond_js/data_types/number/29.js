(12345)
  .toPrecision(2)(
    // '1.2e+4
    12.544,
  )
  .toPrecision(2)(
    // '13'
    12.544,
  )
  .toPrecision(2); // '13'

let num = 0.59645451113245;
num.toPrecision(2); // '0.60'
num.toPrecision(5); // '0.59645'
num.toPrecision(10); // '0.5964545111'
num.toPrecision(20); // '0.59645451113244996044'
