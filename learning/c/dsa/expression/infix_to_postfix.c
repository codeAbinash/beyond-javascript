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

int isEmpty(struct node *top) { return top == NULL; }

int isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
int Prec(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}
struct node* reverse(struct node* head) {
    struct node *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = nextNode = head;
    while (nextNode != NULL) {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}

struct node *infixToPostfix(char *exp) {
    struct node *stack = NULL;
    struct node *output = NULL;

    while (*exp != '\0') {
        if (isOperand(*exp))
            push(*exp, &output);

        else if (*exp == '(')
            push(*exp, &stack);

        else if (*exp == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                push(pop(&stack), &output);
            if (!isEmpty(stack) && peek(stack) != '(')
                return output;
            else
                pop(&stack);
        } else {
            while (!isEmpty(stack) && Prec(*exp) <= Prec(peek(stack)))
                push(pop(&stack), &output);
            push(*exp, &stack);
        }

        exp++;
    }
    while (!isEmpty(stack)) {
        push(pop(&stack), &output);
    }

    return output;
}

void display(struct node *stack) {
    struct node *tmp = stack;
    if (stack == NULL) {
        printf("Empty\n");
        return;
    }
    while (tmp != NULL) {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL;
    char exp[] = "a+d-(c^d-e)-(d^f)*c+d";
    struct node *output = reverse(infixToPostfix(exp));
    display(output);

    return 0;
}