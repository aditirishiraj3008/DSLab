#include <stdio.h>
#include<string.h>
#define MAXSIZE 100

char stack[100];
char rev[100];

void PUSH(int *top,char item){
    stack[++*top]=item;
}
char POP(int* top){
    return stack[(*top)--];
}

void main(){
    char str[100];
    printf("enter a string:");
    scanf("%s",str);
    int top=-1;

    for(int i=0;i<strlen(str);i++)
        PUSH(&top,str[i]);

    for (int i=0;i<=strlen(stack);i++)
        rev[i]=POP(&top);

    if (strcmp(str,rev)==0)
        printf("is a palindrome");

    else
        printf("not a palindrome");
}
