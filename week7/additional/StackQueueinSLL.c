//stack and queues in SLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node* NODE;

// Stack PUSH operation using SLL
NODE PUSH(NODE top, int x) {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->link = top;
    top = new_node;
    return top;
}

// Stack POP operation using SLL
NODE POP(NODE top) {
    if (top == NULL) {
        printf("Stack underflow\n");
        return NULL;
    }
    NODE temp = top;
    printf("Popped: %d\n", top->data);
    top = top->link;
    free(temp);
    return top;
}

// Queue Enqueue operation using SLL
NODE enqueue(NODE rear, int x) {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->link = NULL;
    if (rear == NULL) {
        return new_node;
    }
    rear->link = new_node;
    return new_node;
}

// Queue Dequeue operation using SLL
NODE dequeue(NODE front) {
    if (front == NULL) {
        printf("Queue underflow\n");
        return NULL;
    }
    NODE temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->link;
    free(temp);
    return front;
}

// Display function for Stack and Queue
void display(NODE top) {
    if (top == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    NODE top = NULL;    // Stack top
    NODE front = NULL;  // Queue front
    NODE rear = NULL;   // Queue rear

    int choice, x;

    printf("1. Stack PUSH\n");
    printf("2. Stack POP\n");
    printf("3. Display Stack\n");
    printf("4. Enqueue\n");
    printf("5. Dequeue\n");
    printf("6. Display Queue\n");
    printf("7. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Stack PUSH
                printf("Enter element to push: ");
                scanf("%d", &x);
                top = PUSH(top, x);
                break;
            case 2: // Stack POP
                top = POP(top);
                break;
            case 3: // Display Stack
                printf("Stack: ");
                display(top);
                break;
            case 4: // Enqueue
                printf("Enter element to enqueue: ");
                scanf("%d", &x);
                if (front == NULL) {  // If queue is empty
                    front = enqueue(rear, x);
                    rear = front;
                } else {
                    rear = enqueue(rear, x);
                }
                break;
            case 5: // Dequeue
                front = dequeue(front);
                if (front == NULL) {
                    rear = NULL; // If queue becomes empty, reset rear
                }
                break;
            case 6: // Display Queue
                printf("Queue: ");
                display(front);
                break;
            case 7: // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
