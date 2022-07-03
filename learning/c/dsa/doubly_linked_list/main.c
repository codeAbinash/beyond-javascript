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
    if (index == *length + 1) {
        insertEnd(data, &*headRef, &*tailRef, &*length);
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
    *length = *length + 1;
}

void deleteBeginning(struct node **headRef, struct node **tailRef,
                     int *length) {
    struct node *tmp = *headRef;
    if (tmp == NULL) {
        printf("Cannot delete, Empty List\n");
        return;
    }
    if (*length == 1) {
        *headRef = *tailRef = NULL;
        *length = 0;
        free(tmp);
        return;
    }
    tmp->next->prev = NULL;
    *headRef = tmp->next;
    *length = *length - 1;
    free(tmp);
}

void deleteEnd(struct node **headRef, struct node **tailRef, int *length) {
    struct node *tmp = *tailRef;
    if (tmp == NULL) {
        printf("Cannot Delete, Empty List.\n");
        return;
    }
    if (*length == 1) {
        *headRef = *tailRef = NULL;
        *length = 0;
        free(tmp);
        return;
    }
    tmp->prev->next = NULL;
    *tailRef = tmp->prev;
    *length = *length - 1;
    free(tmp);
}
void deleteIndex(int index, struct node **headRef, struct node **tailRef,
                 int *length) {
    struct node *tmp = *headRef;
    int i = 1;
    if (tmp == NULL) {
        printf("Cannot Delete, Empty List.\n");
        return;
    }
    if (index == 1) {
        deleteBeginning(&*headRef, &*tailRef, &*length);
        return;
    }
    if (index == *length) {
        deleteEnd(&*headRef, &*tailRef, &*length);
        return;
    }
    if (index > *length || index < 2) {
        printf("Invalid Index.\n");
        return;
    }
    while (i < index) {
        tmp = tmp->next;
        i++;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    *length = *length-1;
    free(tmp);
}

void reverse(struct node **headRef, struct node **tailRef) {
    struct node *currentNode, *nextNode;
    currentNode = *headRef;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = currentNode->prev;
        currentNode->prev = nextNode;
        currentNode = nextNode;
    }

    currentNode = *headRef;
    *headRef = *tailRef;
    *tailRef = currentNode;
}

int main() {
    struct node *head, *tail;
    int listLength = 0;
    head = tail = NULL;

    insertEnd(10, &head, &tail, &listLength);
    insertEnd(11, &head, &tail, &listLength);
    insertBeginning(100, &head, &tail, &listLength);
    insertEnd(40, &head, &tail, &listLength);
    insertEnd(19, &head, &tail, &listLength);
    insertEnd(1, &head, &tail, &listLength);
    insertAtPos(41,3,&head,&tail,&listLength);
    display(head);
    printf("Reversed : ");
    reverse(&head, &tail);
    display(head);
    deleteEnd(&head,&tail,&listLength);
    display(head);
    deleteIndex(2,&head,&tail,&listLength);
    display(head);

    return 0;
}