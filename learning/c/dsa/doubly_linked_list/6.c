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