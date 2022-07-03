#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *next;
};

struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Not Enough Memory!");
        exit(1);
    }
    return newNode;
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
    if (tail == NULL) return i;
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

void deleteBeginning(struct node **tailRef, int *length) {
    struct node *tail = *tailRef;
    struct node *head;
    if (tail == NULL) {
        printf("Cannot delete, Empty List!\n");
        return;
    }

    head = tail->next;
    *length = *length - 1;
    if (head == tail) {  // single element
        free(head);
        *tailRef = NULL;
        return;
    }

    tail->next = head->next;
    free(head);
}

void deleteEnd(struct node **tailRef, int *length) {
    struct node *tail = *tailRef, *head, *tmp;
    if (tail == NULL) {
        printf("Cannot delete, Empty List!\n");
        return;
    }

    head = tail->next;
    *length = *length - 1;
    if (tail == head) {  // single element
        free(head);
        *tailRef = NULL;
        return;
    }

    tmp = tail->next;
    while (tmp->next != tail) {
        tmp = tmp->next;
    }
    tmp->next = head;
    *tailRef = tmp;
    free(tail);
}

void deletePosition(int index, struct node **tailRef, int *length) {
    struct node *tmp = *tailRef, *del;
    int i = 1;

    if (index == 1) {
        deleteBeginning(tailRef, length);
        return;
    }
    if (index == *length) {
        deleteEnd(tailRef, length);
        return;
    }

    if (index > *length || index < 2) {
        printf("Invalid Index\n");
        return;
    }

    *length = *length - 1;
    while (i < index) {
        tmp = tmp->next;
        i++;
    }
    del = tmp->next;
    tmp->next = del->next;
    free(del);
}

struct node *reverse(struct node *tail) {
    struct node *currentNode, *nextNode, *prevNode;

    if (tail == NULL) return tail;

    currentNode = tail->next;
    nextNode = currentNode->next;

    while (currentNode != tail) {
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = currentNode->next;
        currentNode->next = prevNode;
    }
    nextNode->next = tail;
    return nextNode;
}

int main() {
    struct node *tail;
    int length = 0;
    tail = NULL;

    deleteBeginning(&tail, &length);
    display(tail);
    insertBeginning(10, &tail, &length);
    insertBeginning(13, &tail, &length);
    insertBeginning(0, &tail, &length);
    insertBeginning(11, &tail, &length);
    display(tail);
    tail = reverse(tail);
    display(tail);
    return 0;
}