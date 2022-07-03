#include "stdio.h"
#include "stdlib.h"
struct node {
    int data;
    struct node *prev, *next;
};

struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Not Enough Memory!");
        exit(1);
    }
    return newNode;
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

void deleteBeginning(struct node **headRef, struct node **tailRef,
                     int *length) {
    struct node *tmp = *headRef, *head = *headRef, *tail = *tailRef;
    if (tmp == NULL) {
        printf("Cannot delete, Empty List \n");
        return;
    }

    *length = *length - 1;

    if (head == tail) {
        *headRef = *tailRef = NULL;
        return;
    }

    tail->next = tmp->next;
    tmp->next->prev = tail;
    *headRef = head->next;
    free(tmp);
}

void deleteEnd(struct node **headRef, struct node **tailRef, int * length){
    struct node *head = *headRef, *tail = *tailRef;
    struct node *tmp = *tailRef;
    if (head == NULL) {
        printf("Cannot delete, Empty List \n");
        return;
    }

    *length = *length - 1;

    if (head == tail) {
        *headRef = *tailRef = NULL;
        return;
    }

    *tailRef = tail->prev;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    free(tmp);
}

void deletePosition(int index, struct node **headRef, struct node ** tailRef, int *length){
    int i = 0;
    struct node *tmp = *headRef;
    if(index == 1){
        deleteBeginning(headRef,tailRef,length);
        return;
    }
    if(index == *length){
        deleteEnd(headRef,tailRef,length);
        return;
    }

    if(index < 1 || index > *length){
        printf("Invalid Index!\n");
        return;
    }

    *length = *length + 1;
    while (i<index-1){
        tmp = tmp->next;
        i++;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
}


int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    int length = 0;
    insertBeginning(100, &head, &tail, &length);
    insertEnd(10, &head, &tail, &length);
    insertEnd(1, &head, &tail, &length);
    insertEnd(9, &head, &tail, &length);
    insertEnd(8, &head, &tail, &length);
    display(head);
    deletePosition(3,&head,&tail,&length);
    display(head);
    return 0;
}