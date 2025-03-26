//multiply two polynomials using circular doubly linked list

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

NODE multiply(NODE poly1, NODE poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    NODE result = NULL;
    NODE ptr1 = poly1;

    do {
        NODE ptr2 = poly2;
        do {
            int C = ptr1->coef * ptr2->coef;
            int E = ptr1->exp + ptr2->exp;

            insert(&result, C, E);

            ptr2 = ptr2->rlink;
        } while (ptr2 != poly2);
        ptr1 = ptr1->rlink;
    } while (ptr1 != poly1);

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
    printf("Enter no of terms in poly: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coef and exp for term %d: ", i + 1);
        scanf("%d %d", &C, &E);
        insert(poly, C, E);
    }
}

int main() {
    NODE poly1 = NULL;
    NODE poly2 = NULL;

    printf("Enter 1st poly:\n");
    input(&poly1);

    printf("Enter 2nd poly:\n");
    input(&poly2);

    printf("1st poly: ");
    disp(poly1);

    printf("2nd poly: ");
    disp(poly2);

    NODE result = multiply(poly1, poly2);

    printf("after multiplication: ");
    disp(result);

    return 0;
}
