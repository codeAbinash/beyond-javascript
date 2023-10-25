BigInt(100);
BigInt(''); // 0n
BigInt(' '); // 0n
BigInt('123'); // 123n
BigInt([0]); // 0n
BigInt([10]); // 10n
BigInt('0b10'); // 2n
BigInt('0x10'); // 16n
BigInt('0o10'); // 8n

BigInt(); // TypeError: Cannot convert undefined to a BigInt
BigInt(10.3); // RangeError: The number 10.3 cannot be converted to a BigInt because it is not an integer
BigInt('200R'); // SyntaxError: Cannot convert 200R to a BigInt
BigInt('Hello'); // SyntaxError: Cannot convert Hello to a BigInt

BigInt(null); // TypeError: Cannot convert null to a BigInt
BigInt(undefined); // TypeError: Cannot convert undefined to a BigInt
BigInt(Infinity); // RangeError: The number Infinity cannot be converted to a BigInt because it is not an integer

BigInt([0, 1, 2]); // SyntaxError: Cannot convert 0,1,2 to a BigInt
BigInt({}); // SyntaxError: Cannot convert [object Object] to a BigInt
