#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Not Enough Memory!");
        exit(1);
    }
    return newNode;
}
struct node *create() {
    int x;
    struct node *newNode = createNode();
    printf("Enter Data : ");
    scanf("%d", &x);
    if (x == -1) return NULL;
    newNode->data = x;

    printf("Left Child of %d, ", x);
    newNode->left = create();

    printf("Right Child of %d, ", x);
    newNode->right = create();
    return newNode;
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
    struct node *root = create();
    printf("Root : ");
    display(root, 6);
    return 0;
}