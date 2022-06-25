#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *prev, *next;
};

struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    return newNode;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("Empty List!\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int countList(struct node *head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void insertBeginning(int data, struct node **headRef, struct node **tailRef,
                       int *length) {
    struct node *newNode = createNode();
    struct node *tmp = *headRef;

    *length = *length + 1;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = *tailRef = newNode;
        return;
    }

    tmp->prev = newNode;
    newNode->next = tmp;
    *headRef = newNode;
}

void insertEnd(int data, struct node **headRef, struct node **tailRef,
                 int *length) {
    struct node *newNode = createNode();
    struct node *tmp = *tailRef;

    *length = *length + 1;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = *tailRef = newNode;
        return;
    }
    tmp->next = newNode;
    newNode->prev = *tailRef;
    *tailRef = newNode;
}

void insertAtPos(int data, int index, struct node **headRef,
                 struct node **tailRef, int *length) {
    int i = 1;
    struct node *tmp = *headRef;
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index == 1) {
        insertBeginning(data, &*headRef, &*tailRef, &*length);
        return;
    }

    if (index > *length || index < 2) {
        printf("Invalid Index.\n");
        return;
    }

    while (i < index - 1) {
        tmp = tmp->next;
        i++;
    }

    newNode->prev = tmp;
    newNode->next = tmp->next;
    tmp->next = newNode;
    newNode->next->prev = newNode;

}

int main() {
    struct node *head, *tail;
    int listLength = 0;
    head = tail = NULL;

    display(head);
    insertEnd(10,&head,&tail,&listLength);
    display(head);
    insertBeginning(1, &head, &tail, &listLength);
    insertBeginning(5, &head, &tail, &listLength);
    insertBeginning(2, &head, &tail, &listLength);
    display(head);
    // insertAtPos(40, 1, &head, &tail, &listLength);
    insertAtPos(-8, 3, &head, &tail, &listLength);
    display(head);
    insertEnd(10,&head,&tail,&listLength);

    
    display(head);

    return 0;
}