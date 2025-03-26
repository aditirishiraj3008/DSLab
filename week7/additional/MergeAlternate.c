//Merging two lists with alternating nodes in new list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* NODE;

NODE create_list();
void traverse(NODE head);
NODE merge_alternate(NODE head1, NODE head2);

int main() {
    NODE head1 = NULL, head2 = NULL, mergedList = NULL;

    printf("Create first list:\n");
    head1 = create_list();

    printf("Create second list:\n");
    head2 = create_list();

    printf("First list: ");
    traverse(head1);

    printf("Second list: ");
    traverse(head2);

    mergedList = merge_alternate(head1, head2);

    printf("Merged list (alternating nodes): ");
    traverse(mergedList);

    return 0;
}

NODE create_list() {
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

NODE merge_alternate(NODE head1, NODE head2) {
    NODE mergedHead = NULL, cur = NULL;

    // Pointers to traverse both lists
    NODE cur1 = head1;
    NODE cur2 = head2;

    // Loop to alternate between both lists
    while (cur1 != NULL || cur2 != NULL) {
        if (cur1 != NULL) {
            NODE temp = (NODE)malloc(sizeof(struct node));
            temp->data = cur1->data;
            temp->link = NULL;
            if (mergedHead == NULL) {
                mergedHead = temp;
                cur = temp;
            } else {
                cur->link = temp;
                cur = temp;
            }
            cur1 = cur1->link;
        }

        if (cur2 != NULL) {
            NODE temp = (NODE)malloc(sizeof(struct node));
            temp->data = cur2->data;
            temp->link = NULL;
            if (mergedHead == NULL) {
                mergedHead = temp;
                cur = temp;
            } else {
                cur->link = temp;
                cur = temp;
            }
            cur2 = cur2->link;
        }
    }

    return mergedHead;
}
