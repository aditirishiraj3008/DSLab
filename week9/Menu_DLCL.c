//insert and delete in DLCL

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* llink;
    struct Node* rlink;
};

struct Node* create_node(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->llink = temp->rlink = NULL;
    return temp;
}

void ins_beg(struct Node** head, int data) {
    struct Node* temp = create_node(data);

    if (*head == NULL) {
        *head = temp;
        temp->rlink = temp->llink = temp;
    } else {
        struct Node* last = (*head)->llink;

        temp->rlink = *head;
        temp->llink = last;
        last->rlink = temp;
        (*head)->llink = temp;

        *head = temp;
    }
}

void del(struct Node** head, int ele) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* cur = *head;
    struct Node* llink = NULL;


    do {
        if (cur->data == ele) {
            if (cur->rlink == cur && cur->llink == cur) {
                *head = NULL;
                free(cur);
                return;
            }

            if (cur == *head) {
                llink = (*head)->llink;
                *head = cur->rlink;
            } else {
                llink = cur->llink;
            }

            llink->rlink = cur->rlink;
            cur->rlink->llink = llink;

            free(cur);
            return;
        }
        cur = cur->rlink;
    } while (cur != *head);

    printf("Node with value %d not found.\n", ele);
}

void disp(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->rlink;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Delete by Value\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                ins_beg(&head, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                del(&head, value);
                break;

            case 3:
                disp(head);
                break;

            case 4:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

