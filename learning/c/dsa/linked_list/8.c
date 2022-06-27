void insertAtIndex(int data, int index, struct node** headRef) {
    // index starts at 1
    struct node *temp, *newNode;
    int i = 1, count = countList(*headRef);

    if (index == count + 1) {
        insertEnd(data, &*headRef);
        return;
    }

    if (index == 1) {
        insertBeginning(data, *&headRef);
        return;
    }

    if (count < index || index < 2) {
        printf("Invalid Index!\n");
        return;
    }

    temp = *headRef;
    while (i < index - 1) {
        temp = temp->next;
        i++;
    }
    newNode = createNode();
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}