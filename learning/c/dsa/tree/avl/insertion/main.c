#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, height;
    struct node *left, *right;
};

int max(int x, int y){
    return x > y ? x : y;
}
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
int getHeight(struct node* n) {
    if (n == NULL) return 0;
    return n->height;
}


int getBalanceFactor(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T = x->right;

    x->right = y;
    y->left = T;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct node* insert(struct node* n, int data) {
    if (n == NULL) return createNode(data);

    if (data < n->data)
        n->left = insert(n->left, data);
    else if (data > n->data)
        n->right = insert(n->right, data);

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    int bf = getBalanceFactor(n);


    // L L Rotate
    if (bf > 1 && data < n->left->data) 
        return rightRotate(n);
    
    // R R Rotate
    if (bf < -1 && data > n->right->data) 
        return leftRotate(n);
    
    // L R Rotate
    if (bf > 1 && data > n->left->data) { 
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    // R L Rotate
    if (bf < -1 && data < n->right->data) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
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


int main() {
    struct node* root = NULL;
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    printf("Root : ");
    display(root, 4);
    return 0;
}
