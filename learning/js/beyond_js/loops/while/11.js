let i = 0,
  j;

myLoop: while (i < 3) {
  j = 0;
  while (j < 3) {
    if (i == 0 && j == 0) {
      i++;
      continue myLoop;
    }
    console.log(i, j);
    j++;
  }
  i++;
}
