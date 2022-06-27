struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    return newNode;
}