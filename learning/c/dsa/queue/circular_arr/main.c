#define N 5
#include "stdio.h"

struct queue {
    int rear, front;
    int arr[N];
};

void enqueue(int data, struct queue *Q) {
    struct queue *q = Q;
    if ((q->rear + 1) % N == q->front) {
        printf("Overflow!\n");
        return;
    }
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->arr[q->rear] = data;
        return;
    }

    q->rear = q->rear + 1;
    q->arr[q->rear] = data;
}

int dequeue(struct queue *Q) {
    struct queue *q = Q;
    int data;
    if (q->front == -1 && q->rear == -1) {
        printf("Underflow!\n");
        return data;
    }

    if (q->front == q->rear) {
        data = q->arr[q->front];
        q->front = q->rear - 1;
        return data;
    }

    data = q->arr[q->front];
    q->front = (q->front + 1) % N;
    return data;
}
int peek(struct queue Q ){
    if(Q.front == -1 && Q.rear == -1){
        printf("Empty Queue\n");
        return -1;
    }
    return Q.arr[Q.front];
}

void display(struct queue Q) {
    int i = Q.front;
    printf("Queue : ");
    if (Q.rear == -1 && Q.front == -1) {
        printf("Empty :\n");
        return;
    }
    while (i != Q.rear) {
        printf("%d ", Q.arr[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", Q.arr[Q.rear]);
}

int main() {
    struct queue Q;
    Q.front = Q.rear = -1;
    display(Q);
    enqueue(14, &Q);
    enqueue(7, &Q);
    enqueue(2, &Q);
    enqueue(99, &Q);
    enqueue(58, &Q);
    display(Q);
    printf("Dequeue : %d\n",dequeue(&Q));
    printf("Dequeue : %d\n",dequeue(&Q));
    printf("Dequeue : %d\n",dequeue(&Q));
    display(Q);
    printf("Peek : %d\n", peek(Q));
    display(Q);
    return 0;
}