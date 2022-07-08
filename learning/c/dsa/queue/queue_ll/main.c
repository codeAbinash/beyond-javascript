#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *next;
};
struct queue {
    struct node *rear, *front;
};

struct node *createNode() {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Not Enough Memory");
        return NULL;
    }
    return n;
}

void enqueue(int data, struct queue *Q) {
    struct queue *q = Q;
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct queue *Q) {
    struct queue *q = Q;
    struct node *tmp;
    int data;

    if (q->front == NULL) {
        printf("Underflow!\n");
        return -1;
    }

    data = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    free(tmp);
    return data;
}

int peek(struct queue Q){
    if(Q.front == NULL){
        printf("Empty Queue!\n");
        return -1;
    }
    return Q.front->data;
}

void display(struct queue Q) {
    
    struct node *tmp = Q.front;

    printf("Queue : ");
    if (tmp == NULL) {
        printf("Empty!\n");
        return;
    }

    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    struct queue Q;
    Q.front = NULL;
    Q.rear = NULL;
    
    display(Q);
    enqueue(100, &Q);
    enqueue(50, &Q);
    enqueue(10, &Q);
    enqueue(1, &Q);
    enqueue(98, &Q);
    display(Q);
    printf("Peek : %d\n",peek(Q));
    enqueue(56, &Q);
    enqueue(65, &Q);
    enqueue(5, &Q);
    enqueue(8, &Q);
    enqueue(0, &Q);
    display(Q);
    printf("Dequeue : %d\n", dequeue(&Q));
    printf("Dequeue : %d\n", dequeue(&Q));
    printf("Dequeue : %d\n", dequeue(&Q));
    display(Q);
    enqueue(99, &Q);
    display(Q);

    return 0;
}