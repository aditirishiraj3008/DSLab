//evaluate prefix expression
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100
int stack[MAX];
char prefix[MAX];
int top = -1;

void push(int item){
    stack[++top]=item;
}
int pop(){
    if (top==-1)
        return -1;
    return stack[top--];
}
int eval(){
    char t;
    int op1,op2;
    int n=strlen(prefix)-1;
    t=prefix[n--];
    while(t!='\0'){
        if(t!='+'&&t!='-'&&t!='/'&&t!='*'&&t!='^')
            push(t-'0');
        else{
            op2=pop(); op1=pop();
            switch(t){
                case '+': push(op2+op1); break;
                case '-': push(op2-op1); break;
                case '*': push(op2*op1); break;
                case '/': push(op2/op1); break;
                case '^': push(pow(op2,op1)); break;
            }
        }
        t=prefix[n--];
    }
    return pop();
}
void main(){
    printf("enter prefix expr:");
    gets(prefix);
    printf("result:");
    printf("%d\n",eval());
}

