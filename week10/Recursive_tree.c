//recursive creation and print tree
#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode* llink;
    struct tnode* rlink;
};

typedef struct tnode* TNODE;

TNODE createNode(int data) {
    TNODE newNode = (TNODE)malloc(sizeof(struct tnode));
    newNode->data = data;
    newNode->llink = NULL;
    newNode->rlink = NULL;
    return newNode;
}


TNODE createTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    TNODE node = createNode(data);
    printf("Creating llink subtree of %d\n", data);
    node->llink = createTree();
    printf("Creating rlink subtree of %d\n", data);
    node->rlink = createTree();

    return node;
}

void printTree(TNODE root) {
    if (root == NULL) return;
    printTree(root->llink);
    printf("%d ", root->data);
    printTree(root->rlink);
}

int main() {
    TNODE root = createTree(); // Create the binary tree
    printf("\nBinary Tree (Inorder Traversal): ");
    printTree(root);           // Print the binary tree
    printf("\n");

    return 0;
}
