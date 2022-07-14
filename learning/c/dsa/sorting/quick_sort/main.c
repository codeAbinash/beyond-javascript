#include <stdio.h>
void displayArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int tmp;

    for (int j = low; j < high; j++)
        if (arr[j] <= pivot) {
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    
    tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

int main() {
    int data[] = {41,5,1,9,48,5,45,56,1,56,4,8};
    int len = sizeof(data) / sizeof(int);

    displayArray(data, len);
    printf("After Sorting...\n");
    quickSort(data, 0, len - 1);
    displayArray(data, len);
}