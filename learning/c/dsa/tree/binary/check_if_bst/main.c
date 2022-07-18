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

int isBST(struct node *root) {
    static struct node *prev = NULL;

    if (root == NULL) return 1;

    if (!isBST(root->left))
        return 0;
    if (prev != NULL && root->data <= prev->data)
        return 0;
    prev = root;
    return isBST(root->right);
}

int main() {
    struct node *root = newNode(8);
    struct node *n3 = newNode(3);
    struct node *n6 = newNode(6);
    struct node *n10 = newNode(10);
    struct node *n11 = newNode(11);
    struct node *n25 = newNode(25);

    root->left = n6;
    n6->left = n3;

    root->right = n11;
    n11->left = n10;
    n11->right = n25;

    printf("isBST : %d\n", isBST(root));

    return 0;
}