#include "stdio.h"

void dispArr(int *arr,int len){
    int i;
    for(i=0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");

}

void bubbleSort(int *arr, int len){ 
    int i,j,tmp;
    for(i=0;i<len-1;i++)
        for(j=0;j<len-i-1;j++)
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

int main(){
    int arr[] = {9,458,451,874,45,255,1,54,45,7,1};
    int len = sizeof(arr) / sizeof(int);
    
    dispArr(arr,len);
    bubbleSort(arr,len);
    printf("After Sorting... \n");
    dispArr(arr,len);
    return 0;
}

