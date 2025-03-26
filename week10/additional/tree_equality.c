//Write a program to check for equality of two trees

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* llink;
    struct TreeNode* rlink;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->llink = NULL;
    newNode->rlink = NULL;
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
        root->llink = insert(root->llink, data);
    } else if (direction == 2) {
        root->rlink = insert(root->rlink, data);
    }

    return root;
}

int areTreesEqual(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data &&
                areTreesEqual(root1->llink, root2->llink) &&
                areTreesEqual(root1->rlink, root2->rlink));
    }
    return 0;
}

int main() {
    struct TreeNode *root1 = NULL, *root2 = NULL;
    int n, val;

    // Input for tree 1
    printf("Enter number of nodes for tree 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root1 = insert(root1, val);
    }

    // Input for tree 2
    printf("Enter number of nodes for tree 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root2 = insert(root2, val);
    }

    if (areTreesEqual(root1, root2)) {
        printf("The trees are equal.\n");
    } else {
        printf("The trees are not equal.\n");
    }

    return 0;
}
