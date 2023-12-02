// by CodeAntu
#include "stdio.h"

void printArray(int arr[], int n) {
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

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
   int smallest = i;
   int leftChild = 2 * i + 1;
   int rightChild = 2 * i + 2;

   if (leftChild < n && arr[leftChild] < arr[smallest]) {
      smallest = leftChild;
   }
   if (rightChild < n && arr[rightChild] < arr[smallest]) {
      smallest = rightChild;
   }
   if (smallest != i) {
      swap(&arr[i], &arr[smallest]);
      heapify(arr, n, smallest);
   }
}

// Build a min-heap from the array
void buildMinHeap(int arr[], int n) {
   for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(arr, n, i);
   }
}

// Add an element to the heap and maintain heap property
void addToHeap(int arr[], int *n, int data) {
   (*n)++;
   arr[*n - 1] = data;
   int lastIndex = *n - 1;

   // Restore heap property by moving the new element to the correct position
   int parent = (lastIndex - 1) / 2;
   while (parent >= 0 && arr[parent] > arr[lastIndex]) {
      swap(&arr[parent], &arr[lastIndex]);
      lastIndex = parent;
      parent = (lastIndex - 1) / 2;
   }
}

// Delete the root element from the heap and maintain heap property
void deleteFromHeap(int arr[], int *n) {
   arr[0] = arr[*n - 1];
   (*n)--;
   heapify(arr, *n, 0);
}

int main() {
   int arr[10] = {2, 4, 9, 5, 1, 6, 0, 3, 7, 8};
   int n = 10;

   printf("Original array:\n");
   printArray(arr, n);

   // Build a min-heap from the array
   printf("\nBuilding min-heap:\n");
   buildMinHeap(arr, n);
   printArray(arr, n);

   // Add an element to the heap
   int newData = 10;
   printf("\nInserting %d into the heap:\n", newData);
   addToHeap(arr, &n, newData);
   printArray(arr, n);

   // Delete the root element from the heap
   deleteFromHeap(arr, &n);
   printf("\nAfter deleting root:\n ");
   printArray(arr, n);

   return 0;
}
