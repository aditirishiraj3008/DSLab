//add 2 polys using circular doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node* rlink;
    struct node* llink;
};
typedef struct node* NODE;

NODE create(int C, int E) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->coef = C;
    temp->exp = E;
    temp->rlink = temp->llink = temp;
    return temp;
}

void insert(NODE* head, int C, int E) {
    if (C == 0) return;

    NODE temp = create(C, E);
    if (*head == NULL) {
        *head = temp;
    } else {
        NODE last = (*head)->llink;
        temp->rlink = *head;
        (*head)->llink = temp;
        temp->llink = last;
        last->rlink = temp;
    }
}

NODE addpolys(NODE poly1, NODE poly2) {
    if (poly1 == NULL) return poly2;
    if (poly2 == NULL) return poly1;

    NODE result = NULL;
    NODE ptr1 = poly1;
    NODE ptr2 = poly2;

    do {
        if (ptr1->exp > ptr2->exp) {
            insert(&result, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->rlink;
        } else if (ptr1->exp < ptr2->exp) {
            insert(&result, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->rlink;
        } else {
            int C = ptr1->coef + ptr2->coef;
            insert(&result, C, ptr1->exp);
            ptr1 = ptr1->rlink;
            ptr2 = ptr2->rlink;
        }
    } while (ptr1 != poly1 && ptr2 != poly2);

    while (ptr1 != poly1) {
        insert(&result, ptr1->coef, ptr1->exp);
        ptr1 = ptr1->rlink;
    }

    while (ptr2 != poly2) {
        insert(&result, ptr2->coef, ptr2->exp);
        ptr2 = ptr2->rlink;
    }

    return result;
}

void disp(NODE head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    NODE temp = head;
    do {
        if (temp->coef != 0) {
            printf("%dX^%d", temp->coef, temp->exp);
            if (temp->rlink != head && temp->rlink->coef >= 0) {
                printf(" + ");
            }
        }
        temp = temp->rlink;
    } while (temp != head);
    printf("\n");
}

void input(NODE* poly) {
    int n, C, E;
    printf("Enter number of terms in poly: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &C, &E);
        insert(poly, C, E);
    }
}

int main() {
    NODE poly1 = NULL;
    NODE poly2 = NULL;

    printf("Enter the first poly:\n");
    input(&poly1);

    printf("Enter the second poly:\n");
    input(&poly2);

    printf("First poly: ");
    disp(poly1);

    printf("Second poly: ");
    disp(poly2);

    NODE result = addpolys(poly1, poly2);

    printf("Resultant poly after addition: ");
    disp(result);

    return 0;
}
