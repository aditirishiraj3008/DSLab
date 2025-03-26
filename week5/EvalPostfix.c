//evaluate postfix expression
#include <stdio.h>
#include <string.h>
#include <math.h>
char postfix[15];
int stack[15];
int top=-1;

void push(int symbol){
    stack[++top]=symbol;
}
int pop(){
    if (top==-1)
        return -1;
    return stack[top--];
}
int eval(){
    char t;
    int op1,op2;
    int n=0;
    t=postfix[n++];
    while(t!='\0'){
        if(t!='+'&&t!='-'&&t!='/'&&t!='*'&&t!='^')
            push(t-'0');
        else{
            op2=pop(); op1=pop();
            switch(t){
                case '+': push(op1+op2); break;
                case '-': push(op1-op2); break;
                case '*': push(op1*op2); break;
                case '/': push(op1/op2); break;
                case '^': push(pow(op1,op2)); break;
            }
        }
        t=postfix[n++];
    }
    return pop();
}

void main(){
    printf("enter postfix expr:");
    gets(postfix);
    int result=eval();
    printf("result:");
    printf("%d\n",eval());
}
