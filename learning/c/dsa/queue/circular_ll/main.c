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
        exit(1);
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
        q->rear = q->front;
        return;
    }

    newNode->next = q->front;
    q->rear->next = newNode;
    q->rear = newNode;
}



int dequeue(struct queue *Q) {
    struct queue *q = Q;
    struct node *tmp;
    int data;
    if (q->front == NULL) {
        printf("Underflow!\n");
        return data;
    }
    if(q->front == q->rear){
        tmp = q->front;
        q->rear = q->front = NULL;
        data = tmp->data;
        free(tmp);
        return data;
    }
    tmp = q->front;
    data = tmp->data;
    q->front = q->front->next;
    q->rear->next = q->front;
    free(tmp);
    return data;
}

int peek(struct queue Q){
    if(Q.front == NULL){
        printf("Empty Queue\n");
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
    while (tmp->next != Q.front) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}

int main() {
    struct queue Q;
    Q.front = Q.rear = NULL;
    display(Q);
    enqueue(7, &Q);
    enqueue(10, &Q);
    display(Q);
    enqueue(10, &Q);
    printf("Peek : %d\n",peek(Q));
    enqueue(5, &Q);
    display(Q);
    printf("Dequeue : %d\n",dequeue(&Q));
    printf("Dequeue : %d\n",dequeue(&Q));
    printf("Dequeue : %d\n",dequeue(&Q));
    printf("Dequeue : %d\n",dequeue(&Q));
    display(Q);
    return 0;
}