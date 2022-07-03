struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Not Enough Memory!");
        exit(1);
    }
    return newNode;
}