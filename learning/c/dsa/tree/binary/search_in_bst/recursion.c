#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *left, *right;
};
struct node *newNode(int data) {
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

struct node * searchRec(struct node * root, int s){
    if (root == NULL)
        return NULL;
    else if (root->data == s)
        return root;
    else if(root->data > s)
        return searchRec(root->left, s);
    else
        return searchRec(root->right,s);
}


int main() {
    struct node *root = newNode(8);
    struct node *n3 = newNode(3);
    struct node *n6 = newNode(6);
    struct node *n10 = newNode(10);
    struct node *n11 = newNode(11);
    struct node *n25 = newNode(25);
    struct node * searched;
    int find =  6;


    root->left = n6;
    n6->left = n3;

    root->right = n11;
    n11->left = n10;
    n11->right = n25;

    searched = searchRec(root,find);
    if(searched == NULL)
        printf("%d not found\n",find);
    else
        printf("Found : %d\n",searched->data);

    return 0;
}