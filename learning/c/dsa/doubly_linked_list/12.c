void reverse(struct node **headRef, struct node **tailRef) {
    struct node *currentNode, *nextNode;
    currentNode = *headRef;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = currentNode->prev;
        currentNode->prev = nextNode;
        currentNode = nextNode;
    }

    currentNode = *headRef;
    *headRef = *tailRef;
    *tailRef = currentNode;
}