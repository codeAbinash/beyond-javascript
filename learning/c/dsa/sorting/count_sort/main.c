#include "stdio.h"
#include "stdlib.h"

void dispArr(int *arr,int len){
    int i;
    for(i=0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");

}

int maxElem(int *arr, int len) {
    int i, max = arr[0];
    for (i = 0; i < len; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void countSort(int *arr, int len) {
    int i,j;
    int max = maxElem(arr, len);
    int *count = (int *)malloc(sizeof(int) * (max + 1));

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < len; i++)
        count[arr[i]] = count[arr[i]] + 1;


    i = 0; j = 0;
    while(i <= max){
        if(count[i] > 0){
            arr[j] = i;
            j++;
        }
        i++;
    }
    free(count);
}

int main() {
    int arr[] = {9,11,7,0,3,2,5,6};
    int len = sizeof(arr) / sizeof(arr[0]);

    dispArr(arr,len);   
    countSort(arr,len);
    dispArr(arr,len);

    return 0;
}