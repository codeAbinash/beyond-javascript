const numbers = [1, 4, 5, 9, 8, 7, 4, 1];

function greaterThan5(num) {
  return num > 5;
}

numbers.find(greaterThan5); // 9
