function bubbleSort(arr = []) {
  let len = arr.length;
  for (let i = 0; i < len; i++)
    for (let j = 0; j < len; j++)
      if (arr[j] > arr[j + 1]) {
        let tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
}

let arr = [1, 6, 5, 6, 4, 6, 4, 9, 58, 4, 5, 54, 54, 65];
console.log(arr);
bubbleSort(arr); // Pass by reference
console.log('After Sorting...');
console.log(arr);
