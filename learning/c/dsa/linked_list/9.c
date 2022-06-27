void deleteFromBeginning(struct node** headRef) {
    struct node* tmp;
    if (*headRef == NULL) {
        printf("Cannot Delete, Empty List!\n");
        return;
    }
    tmp = *headRef;
    *headRef = tmp->next;
    free(tmp);
}