#include <limits.h>  // Include this for INT_MIN
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct MinHeapQueue {
   int heap[MAX_SIZE];
   int top;
};

struct MinHeapQueue *createMinHeapQueue() {
   struct MinHeapQueue *q = (struct MinHeapQueue *)malloc(sizeof(struct MinHeapQueue));
   if (q == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
   }
   q->top = -1;
   return q;
}

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

int isEmpty(struct MinHeapQueue *q) {
   return q->top == -1;
}

int isFull(struct MinHeapQueue *q) {
   return q->top == MAX_SIZE - 1;
}

void heapUp(int heap[], int n, int i) {
   int parent = (i - 1) / 2;

   if (parent >= 0 && heap[parent] > heap[i]) {
      swap(&heap[parent], &heap[i]);
      heapUp(heap, n, parent);
   }
}

void heapDown(int heap[], int n, int i) {
   int smallest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;

   if (l < n && heap[l] < heap[smallest]) {
      smallest = l;
   }
   if (r < n && heap[r] < heap[smallest]) {
      smallest = r;
   }
   if (smallest != i) {
      swap(&heap[i], &heap[smallest]);
      heapDown(heap, n, smallest);
   }
}

void enqueue(struct MinHeapQueue *q, int data) {
   if (isFull(q)) {
      printf("Queue is full\n");
      return;
   }
   q->heap[++q->top] = data;
   heapUp(q->heap, q->top + 1, q->top);
}

int dequeue(struct MinHeapQueue *q) {
   if (isEmpty(q)) {
      printf("Queue is empty\n");
      return INT_MIN;
   }
   int data = q->heap[0];
   q->heap[0] = q->heap[q->top--];
   heapDown(q->heap, q->top + 1, 0);
   return data;
}

void printMinHeapQueue(struct MinHeapQueue *q) {
   for (int i = 0; i <= q->top; i++) {
      printf("%d ", q->heap[i]);
   }
   printf("\n");
}

int main() {
   struct MinHeapQueue *q = createMinHeapQueue();

   printf("Enqueue elements :- \n");
   enqueue(q, 10);
   enqueue(q, 20);
   enqueue(q, 30);
   enqueue(q, 40);
   enqueue(q, 50);

   printMinHeapQueue(q);

   printf("\nDequeue elements :- \n");
   printf("Deleted: %d\n", dequeue(q));
   printf("Deleted: %d\n", dequeue(q));
   printf("Deleted: %d\n", dequeue(q));

   printf("\nRemaining elements :- \n");
   printMinHeapQueue(q);

   free(q);

   return 0;
}
