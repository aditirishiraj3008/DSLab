//menu driven function to implement Linked lists

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*head=NULL;

typedef struct node* NODE;

void traverse(){
    NODE h=head;
    if(h==NULL)
    {
        printf("list is empty\n");
        return;
    }
    while(h->link!=NULL){
        printf("%d -> ",h->data);
        h=h->link;
    }
    printf("%d",h->data);
}

void create_list(){
    NODE cur;
    cur=head;
    NODE temp=(NODE)malloc(sizeof(struct node));
    printf("Enter ele: ");
    scanf("%d", &temp->data);
    temp->link=NULL;
    if(head==NULL)
        head=temp;
    else{
        while(cur->link!=NULL)
            cur=cur->link;
    cur->link=temp;
    }
}

void insertbefore(int ele,int item){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    // If inserting before the head
    if (head != NULL && head->data == ele) {
        temp->link = head;
        head = temp;
        printf("List after insertion:\n");
        traverse();
        return;
    }

    NODE cur = head, prev = NULL;
    while (cur != NULL && cur->data != ele) {
        prev = cur;
        cur = cur->link;
    }

    if (cur == NULL) {
        printf("Element not found\n");
    } else {
        temp->link = cur;
        prev->link = temp;
    printf("\nlist after insertion:\n");
    traverse();
    }
}

void insertafter(int ele,int item){
    NODE cur = head;
    while (cur != NULL && cur->data != ele) {
        cur = cur->link;
    }

    if (cur == NULL) {
        printf("Element not found\n");
    } else {
        NODE temp = (NODE)malloc(sizeof(struct node));
        temp->data = item;
        temp->link = cur->link;
        cur->link = temp;
    printf("list after insertion:\n");
    traverse();
    }
}

void del(int ele){
    NODE cur,prev;
    if(head==NULL)
        printf("No records to delete\n");
    else{
        cur=head;
        while((cur!=NULL)&&(cur->data!=ele)){
            prev=cur;
            cur=cur->link;
        }
        if(cur==head){
            printf("data deleted\n");
        }
        if(cur==NULL){
            printf("Record not found\n");
            return;
        }
        else{
            prev->link=cur->link;
            printf("datadeleted\n");
        }
        free(cur);
    }
}

void reverse(){
    NODE prev = NULL, curr = head, next = NULL;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    traverse();
}

void sort(){
    if (head == NULL) {
        printf("list is empty - nothing to sort\n");
        return;
    }

    NODE h = head;
    int swapped;
    do {
        swapped = 0;
        h = head;
        while (h->link != NULL) {
            if (h->data > h->link->data) {
                int temp = h->data;
                h->data = h->link->data;
                h->link->data = temp;
                swapped = 1;
            }
            h = h->link;
        }
    } while (swapped);
    traverse();
}

void delalt(){
    if (head == NULL) return;

    NODE cur = head;
    while (cur != NULL && cur->link != NULL) {
        NODE temp = cur->link;
        cur->link = temp->link;
        free(temp);
        cur = cur->link;
    }
    printf("List after deleting alternate nodes:\n");
    traverse();
}

void sortinsert(int item){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;

    if (head == NULL || head->data >= item) {
        temp->link = head;
        head = temp;
    } else {
        NODE cur = head;
        while (cur->link != NULL && cur->link->data < item) {
            cur = cur->link;
        }
        temp->link = cur->link;
        cur->link = temp;
    }

    printf("list after insertion in sorted form:\n");
    traverse();
}

int main() {
    int choice, item, ele,ch=0;
    printf("Create the list):\n");
    while (1) {
        printf("Enter 0 to continue creating the list or -1 to stop: ");
        scanf("%d", &ch);
        if (ch == -1) break;
        create_list();
    }
    printf("\n1.Insert ele before another\n");
    printf("2.Insert ele after another\n");
    printf("3.Delete an element\n");
    printf("4.Traverse list\n");
    printf("5.Reverse list\n");
    printf("6.Sort list\n");
    printf("7.Delete every alternate node\n");
    printf("8.Insert ele in sorted list\n");
    printf("9.Exit\n");
    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter ele to insert: ");
            scanf("%d", &item);
            printf("Enter the ele before which we need to insert: ");
            scanf("%d", &ele);
            insertbefore(ele,item);
            break;
        case 2:
            printf("Enter ele to insert: ");
            scanf("%d", &item);
            printf("Enter the ele after which we need to insert: ");
            scanf("%d", &ele);
            insertafter(ele,item);
            break;
        case 3:
            printf("Enter the element to delete: ");
            scanf("%d", &ele);
            del(ele);
            printf("list after deletion:\n");
            traverse();
            break;
        case 4:
            printf("Traversing the list: ");
            traverse();
            break;
        case 5:
            printf("Reversing the list: ");
            reverse();
            break;
        case 6:
            printf("Sorting the list: ");
            sort();
            break;
        case 7:
            printf("Deleting every alternate node: ");
            delalt();
            break;
        case 8:
            printf("Insertion in sorted list: ");
            printf("Enter ele to insert: ");
            scanf("%d", &item);
            sortinsert(item);
            break;
        case 9:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
