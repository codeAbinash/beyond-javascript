#include "stdio.h"
int search(int elem,int *arr, int end){
    int i;
    for(i=0;i<end;i++)
        if(arr[i] == elem)
            return i;
    return -1;
}


int main(){
    int arr[] = {10,55,978,45,22,0,5,44};
    int end = 8;
    int searchElem = 22;

    printf("Index of %d : %d \n", searchElem, search(searchElem,arr,end));

    return 0;
}