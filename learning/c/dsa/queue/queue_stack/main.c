#include "stdio.h"
#include "stdlib.h"
#define N 5
struct queue {
    int s1[N], s2[N];
    int top1, top2, count;
};

void push1(int data, struct queue *Q) {
    Q->s1[++Q->top1] = data;
}
void push2(int data, struct queue *Q) {
    Q->s2[++Q->top2] = data;
}

int pop1(struct queue *Q) {
    return (Q->s1[Q->top1--]);
}
int pop2(struct queue *Q) {
    return (Q->s2[Q->top2--]);
}
void enqueue(int data, struct queue *Q) {
    push1(data, Q);
    Q->count++;
}
int dequeue(struct queue *Q) {
    int i, data;
        if (Q->top1 == -1) {
        printf("Empty \n");
        return -1;
    }
    for (i = 0; i < Q->count; i++) {
        push2(pop1(Q), Q);
    }
    data = pop2(Q);
    Q->count--;
    for (i = 0; i < Q->count; i++) {
        push1(pop2(Q), Q);
    }
    return data;
}
void display(struct queue *Q) {
    int i;
    printf("Queue : ");
    if (Q->top1 == -1) {
        printf("Empty \n");
        return;
    }
    for (i = 0; i <= Q->top1; i++) {
        printf("%d ", Q->s1[i]);
    }
    printf("\n");
}

int main() {
    struct queue Q;
    Q.count = 0;
    Q.top1 = Q.top2 = -1;
    enqueue(45,&Q);
    enqueue(3,&Q);
    enqueue(4,&Q);
    display(&Q);
    printf("Dequeue  : %d\n",dequeue(&Q));
    printf("Dequeue  : %d\n",dequeue(&Q));
    display(&Q);
    enqueue(9,&Q);
    enqueue(7,&Q);
    display(&Q);
    return 0;
}