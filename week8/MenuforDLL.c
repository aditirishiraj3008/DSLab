// menu driven program to perform operations on doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct dnode {
    struct dnode* llink;
    int data;
    struct dnode* rlink;
} *head = NULL;

typedef struct dnode* DNODE;

void insert_rear() {
    DNODE temp = (DNODE)malloc(sizeof(struct dnode));
    printf("Enter ele to insert at rear: ");
    scanf("%d", &temp->data);
    temp->llink = temp->rlink = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    DNODE cur = head;
    while (cur->rlink != NULL)
        cur = cur->rlink;
    cur->rlink = temp;
    temp->llink = cur;
}

void del_rear() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    if (head->rlink == NULL) {
        free(head);
        head = NULL;
        return;
    }

    DNODE cur = head;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    cur->llink->rlink = NULL;
    free(cur);
}

void insert_pos(int pos, int item) {
    DNODE temp = (DNODE)malloc(sizeof(struct dnode));
    temp->data = item;
    temp->llink = temp->rlink = NULL;

    if (pos == 0) {
        temp->rlink = head;
        if (head != NULL) {
            head->llink = temp;
        }
        head = temp;
        return;
    }

    DNODE cur = head;
    for (int i = 0; i < pos - 1 && cur != NULL; i++) {
        cur = cur->rlink;
    }

    if (cur == NULL) {
        printf("Position is beyond length\n");
        free(temp);
        return;
    }

    temp->rlink = cur->rlink;
    temp->llink = cur;
    if (cur->rlink != NULL) {
        cur->rlink->llink = temp;
    }
    cur->rlink = temp;
}

void del_pos(int pos) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    DNODE cur = head;

    if (pos == 0) {
        head = cur->rlink;
        if (head != NULL) {
            head->llink = NULL;
        }
        free(cur);
        return;
    }

    for (int i = 0; i < pos && cur != NULL; i++) {
        cur = cur->rlink;
    }

    if (cur == NULL) {
        printf("Position is beyond length\n");
        return;
    }

    if (cur->llink != NULL) {
        cur->llink->rlink = cur->rlink;
    }

    if (cur->rlink != NULL) {
        cur->rlink->llink = cur->llink;
    }

    free(cur);
}

void insert_after(int target, int item) {
    DNODE cur = head;

    while (cur != NULL && cur->data != target) {
        cur = cur->rlink;
    }

    if (cur == NULL) {
        printf("%d not found\n", target);
        return;
    }

    DNODE temp = (DNODE)malloc(sizeof(struct dnode));
    temp->data = item;
    temp->llink = cur;
    temp->rlink = cur->rlink;

    if (cur->rlink != NULL) {
        cur->rlink->llink = temp;
    }
    cur->rlink = temp;
}

void insert_before(int target, int item) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    if (head->data == target) {
        insert_rear(item);
        return;
    }

    DNODE cur = head;

    while (cur != NULL && cur->data != target) {
        cur = cur->rlink;
    }

    if (cur == NULL) {
        printf("%d not found\n", target);
        return;
    }

    DNODE temp = (DNODE)malloc(sizeof(struct dnode));
    temp->data = item;
    temp->llink = cur->llink;

    if (cur->llink != NULL) {
        cur->llink->rlink = temp;
    }
    temp->rlink = cur;
    cur->llink = temp;
}

void traverse() {
    DNODE h = head;
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->rlink;
    }
    printf("\n");
}

void reverse() {
    DNODE cur = head;
    DNODE temp = NULL;

    while (cur != NULL) {
        temp = cur->llink;
        cur->llink = cur->rlink;
        cur->rlink = temp;
        cur = cur->llink;
    }

    if (temp != NULL) {
        head = temp->llink;
    }
}

int main() {
    int choice, item, pos;
    printf("\n1. Insert element at rear\n");
    printf("2. Delete ele from rear\n");
    printf("3. Insert ele at pos\n");
    printf("4. Delete ele from pos\n");
    printf("5. Insert ele after ele\n");
    printf("6. Insert ele before ele\n");
    printf("7. Traverse list\n");
    printf("8. Reverse list\n");
    printf("9. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_rear();
                printf("List after insertion: ");
                traverse();
                break;
            case 2:
                del_rear();
                printf("List after deletion from rear: ");
                traverse();
                break;
            case 3:
                printf("Enter ele to insert: ");
                scanf("%d", &item);
                printf("Enter pos: ");
                scanf("%d", &pos);
                insert_pos(pos, item);
                printf("List after insertion: ");
                traverse();
                break;
            case 4:
                printf("Enter pos to delete: ");
                scanf("%d", &pos);
                del_pos(pos);
                printf("List after deletion: ");
                traverse();
                break;
            case 5:
                printf("Enter ele to insert: ");
                scanf("%d", &item);
                printf("Enter ele after which to insert: ");
                scanf("%d", &pos);
                insert_after(pos, item);
                printf("List after insertion: ");
                traverse();
                break;
            case 6:
                printf("Enter ele: ");
                scanf("%d", &item);
                printf("Enter ele before which to insert: ");
                scanf("%d", &pos);
                insert_before(pos, item);
                printf("List after insertion: ");
                traverse();
                break;
            case 7:
                printf("Traversing the list: ");
                traverse();
                break;
            case 8:
                reverse();
                printf("List after reversal: ");
                traverse();
                break;
            case 9:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
