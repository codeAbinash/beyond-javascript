#include "stdio.h"
void insertAtStart(int elem, int *arr, int *end, int MAX_LEN) {
    int i;
    if (*end >= MAX_LEN) {
        printf("Array Limit Exceed.\n");
        return;
    }
    for (i = *end - 1; i >= 0; i--) arr[i + 1] = arr[i];

    arr[0] = elem;
    *end = *end + 1;
}
void printArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int end = 5;
    int MAX_LEN = sizeof(arr) / sizeof(int);

    printArray(arr, end);
    insertAtStart(6, arr, &end, MAX_LEN);
    insertAtStart(7, arr, &end, MAX_LEN);
    insertAtStart(8, arr, &end, MAX_LEN);
    printArray(arr, end);

    return 0;
}
