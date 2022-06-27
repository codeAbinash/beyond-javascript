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
    free(tmp);
}