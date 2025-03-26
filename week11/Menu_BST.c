//menu driven -BST

#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode* llink;
    struct tnode* rlink;
};

struct tnode* create(int data) {
    struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

struct tnode* insert(struct tnode* root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->data) {
        root->llink = insert(root->llink, data);
    } else if (data > root->data) {
        root->rlink = insert(root->rlink, data);
    }
    return root;
}

struct tnode* min(struct tnode* node) {
    struct tnode* cur = node;
    while (cur && cur->llink != NULL) {
        cur = cur->llink;
    }
    return cur;
}

struct tnode* del(struct tnode* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->llink = del(root->llink, data);
    } else if (data > root->data) {
        root->rlink = del(root->rlink, data);
    } else {
        if (root->llink == NULL) {
            struct tnode* temp = root->rlink;
            free(root);
            return temp;
        } else if (root->rlink == NULL) {
            struct tnode* temp = root->llink;
            free(root);
            return temp;
        }
        struct tnode* temp = min(root->rlink);
        root->data = temp->data;
        root->rlink = del(root->rlink, temp->data);
    }
    return root;
}

struct tnode* search(struct tnode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->llink, data);
    }
    return search(root->rlink, data);
}

void inorder(struct tnode* root) {
    if (root != NULL) {
        inorder(root->llink);
        printf("%d ", root->data);
        inorder(root->rlink);
    }
}

int main() {
    struct tnode* root = NULL;
    int ch, data;
    printf("\nMenu-BST\n");
    printf("1. Insert an ele\n");
    printf("2. Delete an ele\n");
    printf("3. Search for an ele\n");
    printf("4. Traverse inorder\n");
    printf("5. Exit\n");
    do {
        printf("Enter your ch: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter ele to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted\n");
                break;

            case 2:
                printf("Enter ele to delete: ");
                scanf("%d", &data);
                root = del(root, data);
                printf("Deleted\n");
                break;

            case 3:
                printf("Enter ele to search: ");
                scanf("%d", &data);
                struct tnode* result = search(root, data);
                if (result != NULL) {
                    printf("ele found\n", data);
                } else {
                    printf("ele not found\n", data);
                }
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 5);

    return 0;
}
