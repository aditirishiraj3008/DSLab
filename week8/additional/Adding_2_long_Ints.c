//addition of two long positive integer numbers

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newnode = createNode(data);
    if (head == NULL)
        return newnode;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct Node* reverseList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}


struct Node* addTwoLists(struct Node* first, struct Node* second) {
    first = reverseList(first);
    second = reverseList(second);

    struct Node* result = NULL;
    int carry = 0;

    while (first != NULL || second != NULL || carry > 0) {
        int sum = carry;

        if (first != NULL) {
            sum += first->data;
            first = first->next;
        }

        if (second != NULL) {
            sum += second->data;
            second = second->next;
        }

        carry = sum / 10;
        result = insertEnd(result, sum % 10);
    }

    // Reverse the result to get the final sum
    result = reverseList(result);
    return result;
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* createListFromString(char* str) {
    struct Node* head = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        head = insertEnd(head, str[i] - '0');
    }
    return head;
}

int main() {
    char num1[1000], num2[1000];

    // Input two large numbers as strings
    printf("Enter the first large number: ");
    scanf("%s", num1);
    printf("Enter the second large number: ");
    scanf("%s", num2);

    // Create linked lists from the input strings
    struct Node* first = createListFromString(num1);
    struct Node* second = createListFromString(num2);

    // Add the two lists
    struct Node* result = addTwoLists(first, second);

    // Print the result
    printf("Sum: ");
    printList(result);

    return 0;
}

