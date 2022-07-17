#include "stdio.h"
#include "stdlib.h"

struct node {
    char data;
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

void push(char data, struct node **top) {
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

char pop(struct node **top) {
    struct node *tmp = *top;
    char data;
    if (tmp == NULL) return '\0';
    data = tmp->data;
    *top = tmp->next;
    free(tmp);
    return data;
}

char peek(struct node *top) {
    if (top == NULL) return '\0';
    return top->data;
}

int checkParentheses(char *exp) {
    char *tmp = exp;
    struct node *stack = NULL;

    while (*tmp != '\0') {
        if (*tmp == '(')
            push(*tmp, &stack);
        
        else if (*tmp == ')')
            if (pop(&stack) == '\0')
                return 0;
        tmp++;
    }

    if (peek(stack) != '\0')
        return 0;
    return 1;
}

int main() {
    char exp[] = "a * (b + c) / (10 * 99) - 10";
    int status = checkParentheses(exp);

    printf("Expression : %s\nStatus : " , exp);

    if(status)
        printf("OK");
    else
        printf("Wrong");

    return 0;
}