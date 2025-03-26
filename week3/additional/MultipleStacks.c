#include <stdio.h>

#define MAX_SIZE 15  //Total size

int arr[MAX_SIZE];     // Array
int top[MAX_SIZE];     // top index of each stack
int b[MAX_SIZE];    // boundary index of each stack
int n;                 // Total number of stacks
int size;              // Total size of each stack

//initialize stacks
void initialize(int numStacks, int stackSize) {
    n = numStacks;
    size = stackSize / n;
    for (int i = 0; i < n; i++) {
        b[i] = i * size;         //base for each stack
        top[i] = b[i] - 1;       //top of each stack (just before its base)
    }
}

//if a stack is full
int isFull(int stackNum) {
    return (top[stackNum] == b[stackNum] + size - 1);
}

//if a stack is empty
int isEmpty(int stackNum) {
    return (top[stackNum] < b[stackNum]);
}

//push an element to a stack
void push(int stackNum, int value) {
    if (isFull(stackNum)) {
        printf("Stack is full\n");
    } else {
        top[stackNum]++;
        arr[top[stackNum]] = value;
        printf("Pushed\n");
    }
}

//pop an element from a stack
int pop(int stackNum) {
    if (isEmpty(stackNum)) {
        printf("Stack %d is empty\n", stackNum);
        return -1;
    } else {
        int value = arr[top[stackNum]];
        top[stackNum]--;
        printf("Popped ele:%d\n", value);
        return value;
    }
}

// display the elements of a stack
void display(int stackNum) {
    if (isEmpty(stackNum)) {
        printf("Stack %d is empty\n", stackNum);
    } else {
        printf("Stack %d elements: ", stackNum);
        for (int i = b[stackNum]; i <= top[stackNum]; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void main() {
    int numStacks, stackSize, ch, stackNum, value;

    printf("Enter the total number of stacks: ");
    scanf("%d", &numStacks);

    printf("Enter the total size of the array: ");
    scanf("%d", &stackSize);

    initialize(numStacks, stackSize);

    do {
        printf("\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter stack number: ");
                scanf("%d", &stackNum);
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stackNum, value);
                break;
            case 2:
                printf("Enter stack number: ");
                scanf("%d", &stackNum);
                pop(stackNum);
                break;
            case 3:
                printf("Enter stack number: ");
                scanf("%d", &stackNum);
                display(stackNum);
                break;
            case 4:
                printf("exiting!");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
}
