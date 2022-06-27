
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