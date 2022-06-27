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