#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *next;
};

struct node *createNode() {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Not Enough Memory");
        exit(1);
    }
    return n;
}

void display(struct node *stack) {
    struct node *tmp = stack;
    printf("Stack : ");
    if (stack == NULL) {
        printf("Empty\n");
        return;
    }
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void push(int data, struct node **top) {
    struct node *newNode = createNode();
    struct node *tmp = *top;
    newNode->data = data;

    if (tmp == NULL) {
        newNode->next = NULL;
        *top = newNode;
        return;
    }

    newNode->next = *top;
    *top = newNode;
}


void pop(struct node **top){
    struct node *tmp = *top;
    if(tmp==NULL){
        printf("Underflow!\n");
        return;
    }

    *top = tmp->next;
    free(tmp);
}

int peek(struct node *top){
    if(top == NULL){
        printf("Underflow!\n");
        return -1;
    }
    return top->data;
}


int main() {
    struct node *stack = NULL;
    pop(&stack);
    display(stack);
    push(100, &stack);
    push(1, &stack);
    push(7, &stack);
    push(78, &stack);
    display(stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    display(stack);
    printf("Peek : %d\n",peek(stack));
    pop(&stack);
    display(stack);
    peek(stack);
    return 0;
}