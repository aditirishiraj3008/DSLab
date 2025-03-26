//union and intersection of two doubly linked lists

#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the union of two lists
struct Node* unionLists(struct Node* first, struct Node* second) {
    struct Node* unionList = NULL;

    // Insert all elements from the first list
    while (first != NULL) {
        unionList = insertEnd(unionList, first->data);
        first = first->next;
    }

    // Insert elements from the second list if they are not already in the union list
    while (second != NULL) {
        struct Node* temp = unionList;
        int found = 0;

        while (temp != NULL) {
            if (temp->data == second->data) {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            unionList = insertEnd(unionList, second->data);
        }
        second = second->next;
    }

    return unionList;
}

// Function to find the intersection of two lists
struct Node* intersectionLists(struct Node* first, struct Node* second) {
    struct Node* intersectionList = NULL;

    while (first != NULL) {
        struct Node* temp = second;

        while (temp != NULL) {
            if (first->data == temp->data) {
                intersectionList = insertEnd(intersectionList, first->data);
                break;
            }
            temp = temp->next;
        }
        first = first->next;
    }

    return intersectionList;
}

// Function to create a list from user input
struct Node* createList() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    return head;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    printf("Creating List 1:\n");
    list1 = createList();

    printf("Creating List 2:\n");
    list2 = createList();

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* unionList = unionLists(list1, list2);
    printf("Union: ");
    printList(unionList);

    struct Node* intersectionList = intersectionLists(list1, list2);
    printf("Intersection: ");
    printList(intersectionList);

    return 0;
}
