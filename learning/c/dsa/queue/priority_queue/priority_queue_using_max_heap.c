#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Structure to represent a priority queue
struct PriorityQueue {
   int heap[MAX];
   int top;
};

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

int isPriorityQueueEmpty(struct PriorityQueue *pq) {
   return pq->top == -1;
}

int isPriorityQueueFull(struct PriorityQueue *pq) {
   return pq->top == MAX - 1;
}

// Function to create a new priority queue
struct PriorityQueue *createPriorityQueue() {
   struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
   pq->top = -1;
   return pq;
}

// Function to maintain heap property while adding an element
void heapifyUp(int arr[], int n, int index) {
   int parent = (index - 1) / 2;

   if (parent >= 0 && arr[parent] < arr[index]) {
      swap(&arr[parent], &arr[index]);
      heapifyUp(arr, n, parent);
   }
}

// Function to maintain heap property while removing an element
void heapifyDown(int arr[], int n, int index) {
   int largest = index;
   int left = 2 * index + 1;
   int right = 2 * index + 2;

   if (left < n && arr[left] > arr[largest]) {
      largest = left;
   }
   if (right < n && arr[right] > arr[largest]) {
      largest = right;
   }
   if (largest != index) {
      swap(&arr[index], &arr[largest]);
      heapifyDown(arr, n, largest);
   }
}

// Function to add an element to the priority queue
void enqueue(struct PriorityQueue *pq, int data) {
   if (isPriorityQueueFull(pq)) {
      printf("PriorityQueue is full\n");
      return;
   }
   pq->heap[++pq->top] = data;
   heapifyUp(pq->heap, pq->top + 1, pq->top);
}

// Function to remove and return the highest priority element from the priority queue
int dequeue(struct PriorityQueue *pq) {
   if (isPriorityQueueEmpty(pq)) {
      printf("PriorityQueue is empty\n");
      return -1;
   }
   int data = pq->heap[0];
   pq->heap[0] = pq->heap[pq->top--];
   heapifyDown(pq->heap, pq->top + 1, 0);
   return data;
}

void printPriorityQueue(struct PriorityQueue *pq) {
   for (int i = 0; i <= pq->top; i++) {
      printf("%d ", pq->heap[i]);
   }
   printf("\n");
}

int main() {
   // Create a priority queue
   struct PriorityQueue *pq = createPriorityQueue();
   printPriorityQueue(pq);

   printf("Enqueue elements :- \n");
   enqueue(pq, 10);
   enqueue(pq, 20);
   enqueue(pq, 30);
   enqueue(pq, 40);
   enqueue(pq, 50);

   // Print the priority queue
   printPriorityQueue(pq);

   printf("\nDequeue elements :- \n");
   printf("Dequeued: %d\n", dequeue(pq));
   printf("Dequeued: %d\n", dequeue(pq));
   printf("Dequeued: %d\n", dequeue(pq));

   printf("\nRemaining elements :- \n");
   printPriorityQueue(pq);

   // Free the memory allocated for the priority queue
   free(pq);

   return 0;
}
