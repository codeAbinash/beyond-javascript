void deleteIndex(int index, struct node** headRef) {
    struct node *tmp, *nextNode;
    int i = 1, count = countList(*headRef);
    if (*headRef == NULL) {
        printf("Cannot Delete, Empty List!\n");
        return;
    }

    if (index == 1) {
        deleteFromBeginning(*&headRef);
        return;
    }

    if (count < index || index < 2) {
        printf("Invalid Index.\n");
        return;
    }
    tmp = *headRef;

    while (i < index - 1) {
        tmp = tmp->next;
        i++;
    }

    nextNode = tmp->next;
    tmp->next = nextNode->next;
    free(nextNode);
}