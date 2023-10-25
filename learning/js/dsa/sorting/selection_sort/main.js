function selectionSort(arr = []) {
  let minIndex, i, j, tmp;
  let len = arr.length;
  for (i = 0; i < len; i++) {
    minIndex = i;
    for (j = i + 1; j < len; j++) if (arr[j] < arr[minIndex]) minIndex = j;
    tmp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = tmp;
  }
}

let arr = [1, 2, 3, 6, 4, 9, 8, 7, 9, -4, 5, 4];

console.log(arr);
selectionSort(arr);
console.log('After Sorting...');
console.log(arr);
