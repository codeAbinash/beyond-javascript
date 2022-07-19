struct node * inorderPredecessor(struct node *root){
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node * delete(int data, struct node *root){
    struct node * pre;

    if(root == NULL)
        return NULL;
    
    if (root->left == NULL && root->right == NULL)
        return NULL;
    if (data < root->data){
        root->left  = delete(data,root->left);
    }
    else if(data > root->data)
        root->right = delete(data, root->right);
    else{
        pre = inorderPredecessor(root);
        root->data = pre->data;
        root->left = delete(pre->data, root->left);
    }
    return root;
}

