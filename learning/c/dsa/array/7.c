#include "stdio.h"

int delete (int index, int *arr, int *end, int MAX_LEN) {
    int i, deletedElement;
    if (index < 0 || index >= *end) {
        printf("Index out of bound.\n");
        return 0;
    }
    deletedElement = arr[index];
    for (i = index; i < *end - 1; i++) {
        arr[i] = arr[i+ 1];
    }

    *end = *end - 1;
    return deletedElement;
}

void dispArr(int *arr, int end) {
    int i;
    for (i = 0; i < end; i++) printf("%d ", *(arr + i));
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int end = 5;
    int MAX_LEN = sizeof(arr) / sizeof(int);
    dispArr(arr, end);
    printf("Deleted element : %d\n", delete (3, arr, &end, MAX_LEN));
    dispArr(arr, end);
    return 0;
}