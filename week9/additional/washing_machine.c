/*Develop a C application to simulate a washing machine renting system using a circular doubly linked list.
User books the washing machine for a certain amount of time and soon after the time duration,
the washing machine will be handed over to the next person in the queue for use.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[30];
    int time;  //in minutes
    struct User* rlink;
    struct User* llink;
};
typedef struct User* NODE;

NODE create_node(char* name, int time) {
    NODE temp = (NODE)malloc(sizeof(struct User));
    strcpy(temp->name, name);
    temp->time = time;
    temp->rlink = temp->llink = temp;
    return temp;
}

void ins(NODE* head, char* name, int time) {
    NODE temp = create_node(name, time);
    if (*head == NULL) {
        *head = temp;
    } else {
        NODE last = (*head)->llink;
        temp->rlink = *head;
        (*head)->llink = temp;
        temp->llink = last;
        last->rlink = temp;
    }
}

void del(NODE* head, char* name) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    NODE temp = *head;
    NODE prev = NULL;
    int found = 0;

    do {
        if (strcmp(temp->name, name) == 0) {
            found = 1;
            if (temp->rlink == temp) {  // Only one user in the queue
                *head = NULL;
            } else {
                temp->llink->rlink = temp->rlink;
                temp->rlink->llink = temp->llink;
                if (*head == temp) {
                    *head = temp->rlink;
                }
            }
            free(temp);
            printf("User %s's booking has been canceled.\n", name);
            break;
        }
        prev = temp;
        temp = temp->rlink;
    } while (temp != *head);

    if (!found) {
        printf("User %s not found in the queue!\n", name);
    }
}

// Move the washing machine to the next user after the current user's time ends
void nextUser(NODE* head) {
    if (*head == NULL) {
        printf("Queue is empty, no users to process!\n");
        return;
    }

    printf("User %s has finished using the washing machine.\n", (*head)->name);
    printf("Handing over the washing machine to the next user.\n");
    *head = (*head)->rlink;  // Move to the next user in the queue
}

// Display the current queue of users
void displayQueue(NODE head) {
    if (head == NULL) {
        printf("No users in the queue.\n");
        return;
    }

    NODE temp = head;
    printf("Washing machine queue:\n");
    do {
        printf("User: %s, Time: %d minutes\n", temp->name, temp->time);
        temp = temp->rlink;
    } while (temp != head);
}

// Simulate the washing machine booking system
int main() {
    NODE queue = NULL;
    int choice, time;
    char name[30];

    while (1) {
        printf("\nWashing Machine Booking\n");
        printf("1. Book a washing machine\n");
        printf("2. Cancel a booking\n");
        printf("3. Move to the next user\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter user name: ");
                scanf("%s", name);
                printf("Enter booking time (in minutes): ");
                scanf("%d", &time);
                ins(&queue, name, time);
                break;

            case 2:
                printf("Enter user name to cancel booking: ");
                scanf("%s", name);
                del(&queue, name);
                break;

            case 3:
                nextUser(&queue);
                break;

            case 4:
                displayQueue(queue);
                break;

            case 5:
                printf("Exiting.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
