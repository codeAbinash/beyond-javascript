// by codeAntu
#include "stdio.h"

void printArr(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void heapify(int a[], int n, int i) {
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;

   if (l < n && a[l] > a[largest]) {
      largest = l;
   }
   if (r < n && a[r] > a[largest]) {
      largest = r;
   }
   if (largest != i) {
      swap(&a[i], &a[largest]);
      heapify(a, n, largest);
   }
}

void heapSort(int arr[], int n) {
   // Build max heap
   for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(arr, n, i);
   }

   // Extract elements from the heap one by one
   for (int i = n - 1; i >= 0; i--) {
      // Swap the root (maximum element) with the last element
      swap(&arr[0], &arr[i]);

      // Heapify the reduced heap
      heapify(arr, i, 0);
   }
}

int main() {
   int n = 10;
   int arr[] = {2, 4, 9, 5, 1, 6, 0, 3, 7, 8};

   printf("Before sorting: ");
   printArr(arr, n);

   // Perform heap sort
   heapSort(arr, n);

   printf("After sorting: ");
   printArr(arr, n);

   return 0;
}
