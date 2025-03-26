/*Merge two lists to obtain a new linked list Z in which the
nodes are also in the non-decreasing order*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* NODE;

NODE create_sorted_list();
void traverse(NODE head);
NODE merge_sorted_lists(NODE head1, NODE head2);

int main() {
    NODE head1 = NULL, head2 = NULL, mergedList = NULL;

    printf("Create first sorted list:\n");
    head1 = create_sorted_list();

    printf("Create second sorted list:\n");
    head2 = create_sorted_list();

    printf("First sorted list: ");
    traverse(head1);

    printf("Second sorted list: ");
    traverse(head2);

    mergedList = merge_sorted_lists(head1, head2);

    printf("Merged sorted list: ");
    traverse(mergedList);

    return 0;
}

NODE create_sorted_list() {
    NODE head = NULL, cur, temp;
    int ch, ele;

    while (1) {
        printf("Enter 1 to add element or -1 to stop: ");
        scanf("%d", &ch);
        if (ch == -1) break;

        temp = (NODE)malloc(sizeof(struct node));
        printf("Enter element: ");
        scanf("%d", &ele);
        temp->data = ele;
        temp->link = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            cur = head;
            while (cur->link != NULL) {
                cur = cur->link;
            }
            cur->link = temp;
        }
    }

    return head;
}

void traverse(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    NODE cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
    printf("NULL\n");
}

NODE merge_sorted_lists(NODE head1, NODE head2) {
    NODE mergedHead = NULL, cur = NULL;

    // Traverse both lists
    while (head1 != NULL && head2 != NULL) {
        NODE temp = (NODE)malloc(sizeof(struct node));

        if (head1->data <= head2->data) {
            temp->data = head1->data;
            head1 = head1->link;
        } else {
            temp->data = head2->data;
            head2 = head2->link;
        }
        temp->link = NULL;

        if (mergedHead == NULL) {
            mergedHead = temp;
            cur = mergedHead;
        } else {
            cur->link = temp;
            cur = temp;
        }
    }

    while (head1 != NULL) {
        NODE temp = (NODE)malloc(sizeof(struct node));
        temp->data = head1->data;
        temp->link = NULL;
        cur->link = temp;
        cur = temp;
        head1 = head1->link;
    }

    while (head2 != NULL) {
        NODE temp = (NODE)malloc(sizeof(struct node));
        temp->data = head2->data;
        temp->link = NULL;
        cur->link = temp;
        cur = temp;
        head2 = head2->link;
    }

    return mergedHead;
}
