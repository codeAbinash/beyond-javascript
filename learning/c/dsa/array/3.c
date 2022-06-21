#include "stdio.h"
void insertAtEnd(int, int *, int *, int);
void printArray(int *, int);

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6};
    int MAX_LEN = sizeof(arr) / sizeof(int);
    int end = 6;

    printArray(arr, end);

    insertAtEnd(100, arr, &end, MAX_LEN);
    insertAtEnd(55, arr, &end, MAX_LEN);
    insertAtEnd(0, arr, &end, MAX_LEN);
    
    printArray(arr, end);

    return 0;
}
void insertAtEnd(int elem, int *arr, int *end, int MAX_LEN) {
    if (*end >= MAX_LEN) {
        printf("Array length limit exceed.");
        return;
    }
    arr[*end] = elem;
    *end = *end + 1;
}

void printArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}