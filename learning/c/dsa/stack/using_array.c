#define N 5
#include "stdio.h"

struct Stack {
    int elem[N], top;
};

void push(int data, struct Stack *s) {
    if (s->top == N - 1) {
        printf("Overflow!\n");
        return;
    }
    s->top++;
    s->elem[s->top] = data;

}
int pop(struct Stack *stack) {
    int elem;
    if (stack->top == -1) {
        printf("Underflow!\n");
        return -1;
    }
    elem = stack->elem[stack->top];
    stack->top--;
    return elem;
}

int peek(struct Stack s) {
    if (s.top == -1) {
        printf("Underflow!\n");
        return -1;
    }
    return s.elem[s.top];
}
void display(struct Stack s) {
    int i;
    printf("Stack : ");
    if (s.top == -1) {
        printf("Empty\n");
        return;
    }
    for (i = 0; i <= s.top; i++) printf("%d ", s.elem[i]);
    // for(i = N - s.top-1;i>0;i--) printf("empty ");
    printf("\n");
}

int main() {
    struct Stack stack1;
    int i;

    stack1.top = -1;

    push(0, &stack1);
    display(stack1);
    push(1, &stack1);
    push(109, &stack1);
    display(stack1);
    push(104, &stack1);
    // printf("Removed : %d\n", pop(&stack1));
    display(stack1);
    printf("Peek : %d", peek(stack1));
    return 0;
}