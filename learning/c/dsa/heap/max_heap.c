// by CodeAntu
#include <stdio.h>

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

// Heapify a subtree rooted at node i in a max-heap
void maxHeapify(int arr[], int n, int i) {
   int largest = i;
   int leftChild = 2 * i + 1;
   int rightChild = 2 * i + 2;

   if (leftChild < n && arr[leftChild] > arr[largest]) {
      largest = leftChild;
   }
   if (rightChild < n && arr[rightChild] > arr[largest]) {
      largest = rightChild;
   }

   if (largest != i) {
      swap(&arr[i], &arr[largest]);
      maxHeapify(arr, n, largest);
   }
}

// Build a max-heap from an array
void buildMaxHeap(int arr[], int n) {
   for (int i = n / 2 - 1; i >= 0; i--) {
      maxHeapify(arr, n, i);
   }
}

// Add an element to the heap and maintain the max-heap property
void insertAndHeapify(int arr[], int *n, int data) {
   (*n)++;
   arr[*n - 1] = data;
   int currentIndex = *n - 1;

   // Move the new element up to maintain the max-heap property
   int parentIndex = (currentIndex - 1) / 2;
   while (currentIndex > 0 && arr[currentIndex] > arr[parentIndex]) {
      swap(&arr[currentIndex], &arr[parentIndex]);
      currentIndex = parentIndex;
      parentIndex = (currentIndex - 1) / 2;
   }
}

// Delete the maximum element from the heap
void deleteMax(int arr[], int *n) {
   if (*n <= 0) {
      printf("Heap is empty\n");
      return;
   }

   arr[0] = arr[*n - 1];
   (*n)--;
   maxHeapify(arr, *n, 0);
}

int main() {
   int arr[10] = {4, 5, 8, 2, 0, 1, 9, 3, 7, 6};
   int n = 10;

   printf("Original array:\n");
   printArray(arr, n);

   printf("\nBuilding max-heap:\n");
   buildMaxHeap(arr, n);
   printArray(arr, n);

   int newData = 10;
   printf("\nInserting %d into the heap:\n", newData);
   insertAndHeapify(arr, &n, newData);
   printArray(arr, n);

   printf("\nDeleting maximum element from the heap:\n");
   deleteMax(arr, &n);
   printArray(arr, n);

   return 0;
}
