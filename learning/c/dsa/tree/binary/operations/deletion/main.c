#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Not enough memory");
        exit(1);
    }
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}


void printSpace(int space) {
    int i = 0;
    while (i < space) {
        printf(" ");
        i++;
    }
}
void display(struct node *root, int space) {
    if (root == NULL) {
        printf("-");
        return;
    }
    space += 3;
    printf("%d\n", root->data);

    if (root->left != NULL) {
        printSpace(space);
        printf("L : ");
        display(root->left, space);
    }
    if (root->right != NULL) {
        printSpace(space);
        printf("R : ");
        display(root->right, space);
    }
}


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


int main() {
    struct node *root = createNode(10);
    
    insert(5,root);
    insert(25,root);
    insert(13,root);
    insert(7,root);
    insert(28,root);
    printf("Root : ");
    display(root,4);
    delete(13,root);
    printf("Root : ");
    display(root, 4);

    printf("Root : ");
    delete(10,root);
    display(root,3);


    return 0;
}