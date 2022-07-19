struct node * searchIter(struct node * root, int data){
    while (root != NULL){
        if (data == root->data)
            return root;
        else if(data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}