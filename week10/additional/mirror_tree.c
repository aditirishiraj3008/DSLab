//Write a program to check if one tree is the mirror image of another tree.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    int direction;
    printf("Where to insert %d? Enter 1 for left, 2 for right: ", data);
    scanf("%d", &direction);

    if (direction == 1) {
        root->left = insert(root->left, data);
    } else if (direction == 2) {
        root->right = insert(root->right, data);
    }

    return root;
}

int areMirrors(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data &&
                areMirrors(root1->left, root2->right) &&
                areMirrors(root1->right, root2->left));
    }
    return 0;
}

int main() {
    struct TreeNode *root1 = NULL, *root2 = NULL;
    int n, val;

    printf("Enter number of nodes for tree 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root1 = insert(root1, val);
    }

    printf("Enter number of nodes for tree 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root2 = insert(root2, val);
    }

    if (areMirrors(root1, root2)) {
        printf("The trees are mirror images of each other.\n");
    } else {
        printf("The trees are not mirror images of each other.\n");
    }

    return 0;
}
