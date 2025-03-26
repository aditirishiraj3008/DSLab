//Recursive function to create and traverse SLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* NODE;

// Function to create a new node
NODE create_node(int data) {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// Recursive function to create the linked list
NODE create_list(NODE head) {
    int data, choice;
    printf("Enter data (-1 to stop): ");
    scanf("%d", &data);

    if (data == -1)
        return head;

    NODE temp = create_node(data);

    if (head == NULL) {
        head = temp;
    } else {
        NODE cur = head;
        while (cur->link != NULL) {
            cur = cur->link;
        }
        cur->link = temp;
    }

    return create_list(head);
}

// Recursive function to traverse the linked list
void traverse(NODE head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", head->data);
    traverse(head->link); // Recursively traverse the next node
}

int main() {
    NODE head = NULL;

    // Create list using recursion
    printf("Creating the list:\n");
    head = create_list(head);

    // Traverse list using recursion
    printf("\nTraversing the list:\n");
    traverse(head);

    return 0;
}
