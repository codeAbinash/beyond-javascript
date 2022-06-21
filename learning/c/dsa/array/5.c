#include "stdio.h"

void insertAt(int elem, int index, int *arr, int *end, int MAX_LEN) {
    int i;
    if (index >= MAX_LEN || index < 0) {
        printf("Index out of bound.\n");
        return;
    }

    *end = *end > index ? *end + 1 : index + 1;
    for (i = *end; i >= index; i--) arr[i + 1] = arr[i];

    arr[index] = elem;
    printf("%d", arr[index]);
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

    insertAt(100, 10, arr, &end, MAX_LEN);
    dispArr(arr, end);
    return 0;
}