#include "stdio.h"
#include "stdlib.h"
struct node {
    int data;
    struct node *prev, *next;
};

struct node *createNode() {
    return (struct node *)malloc(sizeof(struct node));
}

void display(struct node *head) {
    struct node *tmp = head;
    if (head == NULL) {
        printf("Empty List!\n");
        return;
    }
    printf("List : ");

    while (tmp->next != head) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d ", tmp->data);
    printf("\n");
}

int countList(struct node *head) {
    struct node *tmp = head;
    int i = 0;
    if (tmp == NULL) return 0;

    while (tmp->next != head) {
        tmp = tmp->next;
        i++;
    }
    return ++i;
}

void insertBeginning(int data, struct node **headRef, struct node **tailRef,
                     int *length) {
    struct node *newNode = createNode();
    struct node *head = *headRef;
    struct node *tail = *tailRef;

    newNode->data = data;
    *length = *length + 1;

    if (head == NULL) {
        head = tail = newNode;
        head->prev = tail;
        tail->next = head;
        *headRef = *tailRef = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    newNode->prev = tail;
    tail->next = newNode;
    *headRef = newNode;
}

void insertEnd(int data, struct node **headRef, struct node **tailRef,
               int *length) {
    struct node *newNode = createNode();
    struct node *head = *headRef;
    struct node *tail = *tailRef;

    newNode->data = data;
    *length = *length + 1;

    if (head == NULL) {
        head = tail = newNode;
        head->prev = tail;
        tail->next = head;
        *headRef = *tailRef = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    newNode->next = head;
    head->prev = newNode;
    *tailRef = newNode;
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    int length = 0;
    insertBeginning(100, &head, &tail, &length);
    display(head);
    printf("Lne : %d\n", countList(head));
    insertBeginning(180, &head, &tail, &length);
    display(head);
    printf("Lne : %d\n", countList(head));
    insertBeginning(100, &head, &tail, &length);
    display(head);
    printf("Lne : %d\n", countList(head));
    printf("Length : %d\n",length);
    return 0;
}