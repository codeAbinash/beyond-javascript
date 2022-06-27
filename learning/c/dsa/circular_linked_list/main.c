#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *next;
};

struct node *createNode() {
    return (struct node *)malloc(sizeof(struct node));
}

void display(struct node *tail) {
    struct node *tmp = tail;
    if (tmp == NULL) {
        printf("Empty List!\n");
        return;
    }

    tmp = tmp->next;
    printf("List : ");
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while (tmp != tail->next);
    printf("\n");
}

int countList(struct node *tail) {
    struct node *tmp = tail;
    int i = 0;
    if(tail == NULL) return i;
    tmp = tmp->next;
    do {
        i++;
        tail = tail->next;
    } while (tmp != tail->next);
    return i;
}

void insertBeginning(int data, struct node **tailRef, int *length) {
    struct node *newNode = createNode();
    struct node *tmp = *tailRef;

    newNode->data = data;
    *length = *length + 1;

    if (tmp == NULL) {
        newNode->next = newNode;
        *tailRef = newNode;
        return;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void insertEnd(int data, struct node **tailRef, int *length) {
    struct node *newNode = createNode();
    struct node *tmp = *tailRef;

    *length = *length + 1;
    newNode->data = data;

    if (tmp == NULL) {
        *tailRef = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    *tailRef = newNode;
}

void insertPosition(int data, int index, struct node **tailRef, int *length) {
    struct node *tmp = *tailRef;
    struct node *newNode;
    int i = 1;

    if (index == 1) {
        insertBeginning(data, &*tailRef, &*length);
        return;
    }

    if (index == *length + 1) {
        insertEnd(data, tailRef, length);
        return;
    }

    if (index > *length || index < 2) {
        printf("Invalid Index\n");
        return;
    }

    newNode = createNode();
    newNode->data = data;
    tmp = tmp->next;

    while (i < index - 1) {
        tmp = tmp->next;
        i++;
    }
    *length = *length + 1;
}

int main() {
    struct node *tail;
    int length = 0;
    tail = NULL;

    printf("Length : %d",countList(tail));
    insertBeginning(100, &tail, &length);
    display(tail);
    insertPosition(8, 1, &tail, &length);
    insertPosition(8, 1, &tail, &length);
    insertPosition(8, 1, &tail, &length);
    insertPosition(8, 1, &tail, &length);
    display(tail);
    printf("Length : %d",countList(tail));
    return 0;
}