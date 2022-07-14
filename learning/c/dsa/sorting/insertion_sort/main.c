#include "stdio.h"

void displayArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int *arr, int len) {
    int i, j, key;
    for (i = 0; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {6, 5, 4, 6, 5, 96, 54, 56, 9, 1, 6};
    int len = sizeof(arr) / sizeof(int);
    displayArray(arr, len);
    insertionSort(arr, len);
    displayArray(arr, len);

    return 0;
}