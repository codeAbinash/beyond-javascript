#include "stdio.h"

int deleteEnd(int *arr, int *endPtr) {
    int end = *endPtr;
    int deletedElement;
    if (end == 0) {
        printf("Empty Array");
        return 0;
    }

    deletedElement = arr[end - 1];

    *endPtr = *endPtr - 1;
    return deletedElement;
}
void dispArr(int *arr, int end) {
    int i;
    for (i = 0; i < end; i++) printf("%d ", *(arr + i));
    printf("\n");
}
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7};
    int end = 7;
    int MAX_LEN = sizeof(arr) / sizeof(int);

    dispArr(arr,end);
    printf("Deleted Element : %d\n",deleteEnd(arr,&end));
    dispArr(arr,end);

    return 0;
}