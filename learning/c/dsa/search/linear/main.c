#include "stdio.h"

int linearSearch(int searchItem, int *arr, int len) {
    int i;

    for (i = 0; i < len; i++) 
        if(arr[i] == searchItem)
            return i;
    return -1;
}

int main() {
    int arr[] = {1,2,6,99,5,4,66,4,5,1,5,45};
    int len = sizeof(arr) / sizeof(arr[0]);
    int item = 99;
    int index = linearSearch(99,arr,len);
    printf("Search : %d, found at index : %d",item,index);
    return 0;
}