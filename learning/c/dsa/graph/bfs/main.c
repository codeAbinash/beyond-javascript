#include "stdio.h"
#include "stdlib.h"
#define len 5

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

int isEmpty(struct queue *Q) {
    if (Q->front == NULL) return 1;
    return 0;
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

void BFS(int start, struct queue *Q){
    int nodeGraph, i;
    int visited[len] = {0, 0, 0, 0, 0};
    int matrix[len][len] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("BFS : %d ", start);
    visited[start] = 1;
    enqueue(start, Q);
    while (!isEmpty(Q)){
        nodeGraph = dequeue(Q);
        for(i = 0; i < len; i++){
            if(matrix[nodeGraph][i] == 1 && visited[i] == 0){
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i, Q);
            }
        }
    }
}

int main() {
    struct queue Q;
    int start = 2;
    
    Q.front = NULL;
    Q.rear = NULL;

    BFS(3, &Q);

    return 0;
}
