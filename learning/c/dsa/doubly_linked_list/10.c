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