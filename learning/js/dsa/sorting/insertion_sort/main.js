function insertionSort(arr = []) {
  let len = arr.length;
  let key, j;
  for (let i = 0; i < len; i++) {
    key = arr[i];
    j = i - 1;
    while (arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

let arr = [1, 56, 45, 56, 56, 9, 9, 4, 6, 56, 4, 6];

console.log(arr);
insertionSort(arr);
console.log('After Sorting...');
console.log(arr);
