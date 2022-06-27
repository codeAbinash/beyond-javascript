void deleteFromEnd(struct node** headRef) {
    struct node *tmp, *prevNode;
    if (*headRef == NULL) {
        printf("Cannot Delete, Empty List!\n");
        return;
    }
    tmp = *headRef;
    while (tmp->next != NULL) {
        prevNode = tmp;
        tmp = tmp->next;
    }
    if (tmp == *headRef)
        *headRef = NULL;
    else
        prevNode->next = NULL;
    free(tmp);
}