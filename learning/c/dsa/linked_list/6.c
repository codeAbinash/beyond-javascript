void insertBeginning(int data, struct node** headRef) {
    struct node* newNode = createNode();
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}