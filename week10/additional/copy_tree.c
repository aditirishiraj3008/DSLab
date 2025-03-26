//Copy One Tree to Another

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

struct TreeNode* copyTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot;
}

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode *root1 = NULL, *root2 = NULL;
    int n, val;

    printf("Enter number of nodes for the original tree: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root1 = insert(root1, val);
    }

    root2 = copyTree(root1);

    printf("Original tree (inorder): ");
    inorder(root1);
    printf("\nCopied tree (inorder): ");
    inorder(root2);
    printf("\n");

    return 0;
}
