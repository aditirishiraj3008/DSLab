//add 2 polynomials represented as linked lists

#include <stdio.h>
#include <string.h>
#define COMPARE(x,y) (x)>(y)? 1:((x)==(y)? 0:-1)

struct poly_node{
    int exp;
    int coef;
    struct poly_node* link;
}*head=NULL;
typedef struct poly_node* NODE;

void attach(float coefficient,int exponent,NODE *ptr){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct poly_node));
    temp->coef=coefficient;
    temp->exp=exponent;
    temp->link=NULL;
    (*ptr)->link=temp;
    *ptr=temp;
}

NODE poly_add(NODE a,NODE b){
    NODE front,rear,temp;
    int sum;
    rear=(NODE)malloc(sizeof(struct poly_node));
    front=rear;
    while(a&&b){
        switch(COMPARE(a->exp,b->exp)){
        case -1:
            attach(b->coef,b->exp,&rear);
            b=b->link;
            break;

        case 0:
            sum=a->coef+b->coef;
            if(sum) attach(sum,a->exp,&rear);
            a=a->link; b=b->link;
            break;

        case 1:
            attach(a->coef,a->exp,&rear);
            a=a->link;
            break;
        }
    }
    for(;a;a->link)
        attach(a->coef,a->exp,&rear);
    for(;b;b->link)
        attach(b->coef,b->exp,&rear);
    rear->link=NULL;
    temp=front;
    front=front->link;
    free(temp);
    return front;
}

NODE create_poly() {
    NODE head, temp, last;
    int n, coef, exp;

    printf("Enter no of terms: ");
    scanf("%d", &n);
    head = (NODE)malloc(sizeof(struct poly_node));
    head->link = NULL;
    last = head;

    for (int i = 0; i < n; i++) {
        printf("Enter coef and exp for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        attach(coef, exp, &last);
    }

    temp = head;
    head = head->link;
    free(temp);
    return head;
}

void display_poly(NODE head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    NODE temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->link;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    NODE poly1, poly2, poly_sum;

    printf("Enter 1st poly:\n");
    poly1 = create_poly();

    printf("Enter 2nd poly:\n");
    poly2 = create_poly();

    printf("\n1st poly: ");
    display_poly(poly1);

    printf("2nd poly: ");
    display_poly(poly2);

    poly_sum = poly_add(poly1, poly2);

    printf("poly after addition: ");
    display_poly(poly_sum);

    return 0;
}
