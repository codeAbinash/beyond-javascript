#include "stdio.h"
#include "stdlib.h"

void displayArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int *arr, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int *newArr = (int *)malloc(sizeof(int) * (high + 1));

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            newArr[k] = arr[i];
            i++; k++;
        } else {
            newArr[k] = arr[j];
            j++; k++;
        }
    }

    while (i <= mid) {
        newArr[k] = arr[i];
        k++; i++;
    }

    while (j <= high) {
        newArr[k] = arr[j];
        k++; j++;
    }

    for (i = low; i <= high; i++)
        arr[i] = newArr[i];

    free(newArr);
}

void mergeSort(int *arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main() {
    int arr[] = {6,9,5,0,6,8,4,1,0,36,9,7,9,6};
    int len = sizeof(arr) / sizeof(int);
    displayArray(arr, len);
    mergeSort(arr, 0, len - 1);
    printf("After Sorting ...\n");
    displayArray(arr, len);
    return 0;
}