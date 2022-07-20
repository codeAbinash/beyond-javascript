#include "stdio.h"

int binarySearch(int searchItem, int *arr, int len) {
    int low = 0, mid,
    high = len - 1;

    while(low <= high){
        mid = (low + high ) / 2;
        if (searchItem == arr[mid])
            return mid;
        if (searchItem > arr[mid])
            low  = mid+1;
        else
            high = mid - 1;
    }
    // Not Found
    return -1;
}

int main() {
    int arr[] = {1, 6, 5, 9, 11, 26, 58, 74, 98, 99, 155};
    int len = sizeof(arr) / sizeof(arr[0]);
    int item = 99;
    int index = binarySearch(item,arr,len);
    printf("Search %d, found at index : %d", item,index);
    return 0;
}