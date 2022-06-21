#include "stdio.h"

int deleteFront(int *arr, int *endPtr) {
    int end = *endPtr;
    int i,deletedElement;

    if(end == 0) {
        printf("Array out of bound");
        return 0;
    }

    deletedElement = arr[0];
    for(i=0;i<end-1;i++)
        arr[i] = arr[i+1];
    *endPtr = *endPtr -1;

    return deletedElement;

}
void dispArr(int *arr, int end) {
    int i;
    for (i = 0; i < end; i++) printf("%d ", *(arr + i));
    printf("\n");
}


int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int end = 9;
    int MAX_LEN = sizeof(arr) / sizeof(int);

    dispArr(arr,end);
    printf("Deleted Element : %d\n",deleteFront(arr,&end));
    dispArr(arr,end);

    return 0;
}
