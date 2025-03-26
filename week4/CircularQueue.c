//implement the circular queue
#include <stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE];

void update(int *rear){
    *rear=(*rear+(MAXSIZE-1))%MAXSIZE;    //rear updation reversed when queue is full
    return;
}
void addCQ(int *rear,int front,int item){
    *rear=(*rear+1)%MAXSIZE;              //rear updation
    if(*rear==front){
        printf("Queue is full\n");
        update(rear);
    }
    else
        printf("item added\n");
    queue[*rear]=item;     //adding item
}
int deleteCQ(int*front,int rear){
    if(rear==*front)
        printf("Queue is empty\n");
    else{
        *front=(*front+1)%MAXSIZE;     //front is incremented -circular increment
        return queue[*front];
    }
}

void main(){
    int rear,front,item,ch;
    rear=0;front=0;
    while(1){
        printf("\nEnter choice of operation on queues:\n1. add item\n2. deletetion\n3. exit\nchoice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter item to add:");
                scanf("%d",&item);
                addCQ(&rear,front,item);
                continue;
            case 2:
                printf("deleted item:%d",deleteCQ(&front,rear));
                continue;
            case 3:
                printf("exiting!");
                exit(0);
            default:
                printf("invalid choice");
        }
    }
}
