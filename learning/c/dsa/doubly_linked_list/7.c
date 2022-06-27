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