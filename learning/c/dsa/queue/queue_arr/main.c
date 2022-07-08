#include "stdio.h"
#define N 5
struct queue {
    int arr[N];
    int front, rear;
};

void enqueue(int data, struct queue *Q) {
    struct queue *q = Q;

    if (q->rear == N - 1) {
        printf("Overflow!\n");
        return;
    }
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->arr[q->rear] = data;
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(struct queue *Q){
    struct queue *q = Q;
    int val;

    if(q->front == -1 && q->rear == -1){
        printf("Underflow");
        return -1;
    }

    if(q->front == q->rear){
        val = q->arr[q->front];
        q->front = q->rear = -1;
        return val;
    }
    
    val = q->arr[q->front];
    q->front++;
    return val;
}

void display(struct queue Q) {
    int i;
    printf("Queue : ");
    if (Q.rear == -1 && Q.front == -1) {
        printf("Empty\n");
        return;
    }

    for (i = Q.front; i <= Q.rear; i++) printf("%d ", Q.arr[i]);
    printf("\n");
}

int peek(struct queue Q){
    if(Q.front == -1 && Q.rear == -1){
        printf("Underflow.\n");
        return -1;
    }
    return Q.arr[Q.front];
}

int main() {
    struct queue Q;
    Q.front = Q.rear = -1;
    display(Q);
    enqueue(45, &Q);
    enqueue(2, &Q);
    enqueue(1, &Q);
    display(Q);
    enqueue(85, &Q);
    enqueue(5, &Q);
    display(Q);
    printf("Dequeue : %d\n",dequeue(&Q));
    display(Q);
    printf("Peek : %d\n",peek(Q));
    display(Q);
    
    return 0;
}