//Write a program to implement level order traversal on binary search tree
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* llink;
    struct TreeNode* rlink;
};

// Create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->llink = NULL;
    newNode->rlink = NULL;
    return newNode;
}

// Insert into a binary search tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->llink = insert(root->llink, data);
    } else if (data > root->data) {
        root->rlink = insert(root->rlink, data);
    }
    return root;
}

// Define a queue node structure for level order traversal
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

// Enqueue a node into the queue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!temp) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    temp->treeNode = node;
    temp->next = NULL;
    if (*rear == NULL) {
        *front = *rear = temp; // Queue is empty
    } else {
        (*rear)->next = temp;
        *rear = temp; // Update rear
    }
}

// Dequeue a node from the queue
struct TreeNode* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL) {
        return NULL; // Queue is empty
    }
    struct QueueNode* temp = *front;
    struct TreeNode* node = temp->treeNode;
    *front = (*front)->next;
    if (*front == NULL) {
        // If the queue is now empty, reset rear as well
        *rear = NULL;
    }
    free(temp);
    return node;
}

// Level order traversal function
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return; // Empty tree
    }

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    // Start by enqueuing the root
    enqueue(&front, &rear, root);

    while (front != NULL) {
        struct TreeNode* current = dequeue(&front, &rear); // Pass rear here
        printf("%d ", current->data); // Print the current node

        // Enqueue the left child if it exists
        if (current->llink != NULL) {
            enqueue(&front, &rear, current->llink);
        }

        // Enqueue the right child if it exists
        if (current->rlink != NULL) {
            enqueue(&front, &rear, current->rlink);
        }
    }

    printf("\n");
}

int main() {
    struct TreeNode* root = NULL;
    int n, val;

    // Input for the tree
    printf("Enter number of nodes for the tree: ");
    scanf("%d", &n);

    // Insert nodes into the tree
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Perform level order traversal
    printf("Level order traversal: ");
    levelOrderTraversal(root);

    return 0;
}
