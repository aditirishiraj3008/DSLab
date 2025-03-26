#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define Stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);

// Initialize stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push item to stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Pop item from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Error value
    }
    return stack->arr[stack->top--];
}

// Peek top item of stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Error value
    }
    return stack->arr[stack->top];
}

// Queue structure using two stacks
typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;

// Initialize queue
void initQueue(Queue* queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

// Enqueue operation
void enqueue(Queue* queue, int item) {
    push(&queue->stack1, item);
}

// Dequeue operation
int dequeue(Queue* queue) {
    if (isEmpty(&queue->stack2)) {
        // Transfer elements from stack1 to stack2
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return pop(&queue->stack2);
}

int main() {
    Queue queue;
    initQueue(&queue);

    int choice, item;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                printf("Enqueued %d\n", item);
                break;

            case 2:
                item = dequeue(&queue);
                if (item != -1) {
                    printf("Dequeued %d\n", item);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
