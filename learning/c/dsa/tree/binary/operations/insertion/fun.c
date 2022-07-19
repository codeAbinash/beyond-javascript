void insert(int data, struct node *root){
    struct node *prev = NULL;
    struct node *newNode;
    while (root != NULL){
        prev = root;
        if (data == root->data){
            printf("%d is already available", data);
            return;
        }
        
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }

    newNode = createNode(data);
    if (data < prev->data)
        prev->left = newNode;
    else
        prev->right = newNode;
}