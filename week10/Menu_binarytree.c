//menu-binary tree

#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode* llink;
    struct tnode* rlink;
};
typedef struct tnode* TNODE;

TNODE create(int data) {
    TNODE temp = (TNODE)malloc(sizeof(struct tnode));
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

void inorder(TNODE root) {
    if (root == NULL) return;

    TNODE* stack = (TNODE*)malloc(100 * sizeof(TNODE));
    int top = -1;

    TNODE cur = root;
    while (cur != NULL || top != -1) {
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->llink;
        }
        cur = stack[top--];
        printf("%d ", cur->data);
        cur = cur->rlink;
    }
    printf("\n");
    free(stack);
}

void postorder(TNODE root) {
    if (root == NULL) return;

    TNODE* stack1 = (TNODE*)malloc(100 * sizeof(TNODE));
    TNODE* stack2 = (TNODE*)malloc(100 * sizeof(TNODE));
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;
    while (top1 != -1) {
        TNODE cur = stack1[top1--];
        stack2[++top2] = cur;
        if (cur->llink) stack1[++top1] = cur->llink;
        if (cur->rlink) stack1[++top1] = cur->rlink;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");

    free(stack1);
    free(stack2);
}

void preorder(TNODE root) {
    if (root == NULL) return;

    TNODE* stack = (TNODE*)malloc(100 * sizeof(TNODE));
    int top = -1;

    stack[++top] = root;
    while (top != -1) {
        TNODE cur = stack[top--];
        printf("%d ", cur->data);
        if (cur->rlink) stack[++top] = cur->rlink;
        if (cur->llink) stack[++top] = cur->llink;
    }
    printf("\n");
    free(stack);
}

void printParent(TNODE root, int data) {
    if (root == NULL || (root->llink == NULL && root->rlink == NULL)) {
        printf("No parent found\n");
        return;
    }
    if ((root->llink != NULL && root->llink->data == data) || (root->rlink != NULL && root->rlink->data == data)) {
        printf("Parent is %d\n", root->data);
        return;
    }
    printParent(root->llink, data);
    printParent(root->rlink, data);
}

int depth(TNODE root) {
    if (root == NULL) return 0;
    int llinkDepth = depth(root->llink);
    int rlinkDepth = depth(root->rlink);
    return (llinkDepth > rlinkDepth ? llinkDepth : rlinkDepth) + 1;
}

int printAncestors(TNODE root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;

    if (printAncestors(root->llink, data) || printAncestors(root->rlink, data)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int leafcount(TNODE root) {
    if (root == NULL) return 0;
    if (root->llink == NULL && root->rlink == NULL) return 1;
    return leafcount(root->llink) + leafcount(root->rlink);
}

TNODE createTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    TNODE temp = create(data);
    printf("Creating left subtree\n");
    temp->llink = createTree();
    printf("Creating right subtree\n");
    temp->rlink = createTree();
    return temp;
}

int main() {
    TNODE root = NULL;
    int choice, value;

    root = createTree();
    printf("\nMenu-\n");
    printf("1. Inorder Traversal\n");
    printf("2. Postorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Print Parent\n");
    printf("5. Print Depth\n");
    printf("6. Print Ancestors\n");
    printf("7. Count Leaf Nodes\n");
    printf("8. Exit\n");
    do {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder: ");
                inorder(root);
                break;

            case 2:
                printf("Postorder: ");
                postorder(root);
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                break;

            case 4:
                printf("Enter ele to find parent: ");
                scanf("%d", &value);
                printParent(root, value);
                break;

            case 5:
                printf("Depth: %d\n", depth(root));
                break;

            case 6:
                printf("Enter ele to find ancestors: ");
                scanf("%d", &value);
                printf("Ancestors of %d: ", value);
                if (!printAncestors(root, value)) {
                    printf("No ancestors found\n");
                }
                printf("\n");
                break;

            case 7:
                printf("Number of leaf nodes: %d\n", leafcount(root));
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);

    return 0;
}
