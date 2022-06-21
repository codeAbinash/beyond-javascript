#include "stdio.h"
void update(int elem, int index, int *arr, int *end, int MAX_LEN) {
    if (index < 0 || index >= MAX_LEN) {
        printf("Index out of bound\n");
        return;
    }
    if (index > *end) *end = index + 1;

    arr[index] = elem;
}

void dispArr(int *arr, int end) {
    int i;
    for (i = 0; i < end; i++) printf("%d ", *(arr + i));
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6};
    int end = 6;
    int MAX_LEN = sizeof(arr) / sizeof(int);

    dispArr(arr, end);
    update(10, 7, arr, &end, MAX_LEN);
    dispArr(arr, end);
    update(5, 0, arr, &end, MAX_LEN);
    dispArr(arr, end);

    return 0;
}