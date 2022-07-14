#include "stdio.h"

void displayArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int *arr, int len) {
    int i, j, minIndex, tmp;
    for (i = 0; i < len; i++) {
        minIndex = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}

int main() {
    int arr[] = { 4, 8, 1, 3, 6, 4, 6, 45, 58, 4, 96, 45, 41, 5, 4};
    int len = sizeof(arr) / sizeof(int);

    displayArray(arr, len);
    selectionSort(arr, len);
    printf("After Sorting... \n");
    displayArray(arr, len);
    return 0;
}