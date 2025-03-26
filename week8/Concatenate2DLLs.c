#include <stdio.h>
#include <stdlib.h>

struct dnode {
    struct dnode* llink;
    int data;
    struct dnode* rlink;
};

typedef struct dnode* DNODE;

DNODE insert(DNODE head) {
    DNODE temp = (DNODE)malloc(sizeof(struct dnode));
    printf("Enter element: ");
    scanf("%d", &temp->data);
    temp->llink = temp->rlink = NULL;

    if (head == NULL) {
        return temp;
    }

    DNODE cur = head;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return head;
}

void traverse(DNODE head) {
    DNODE cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->rlink;
    }
    printf("\n");
}

DNODE concat(DNODE h1, DNODE h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    DNODE cur = h1;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }

    cur->rlink = h2;
    h2->llink = cur;

    return h1;
}

int main() {
    DNODE h1 = NULL;
    DNODE h2 = NULL;
    int n1, n2;

    printf("Enter number of eles for DLL-X1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        h1 = insert(h1);
    }

    printf("Enter number of eles for DLL-X2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        h2 = insert(h2);
    }

    printf("The 2 DLLs (X1 and X2) are:\n");
    printf("DLL-X1: ");
    traverse(h1);
    printf("DLL-X2: ");
    traverse(h2);

    DNODE h3 = concat(h1, h2);
    printf("concatenated DLL: ");
    traverse(h3);

    return 0;
}

