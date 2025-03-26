//infix to postfix expression
#include <stdio.h>
#include <string.h>
char infix[15];
char postfix[15];
char stack[15];
int top=-1;

int input_prec(char t){
    switch(t){
        case '+': case '-': return 1; break;
        case '*': case '/': return 3; break;
        case '^': return 6; break;
        case '(': return 9; break;
        case ')': return 0; break;
        default: return 7;
    }
}
int stack_prec(char t){
    switch(t){
        case '+': case '-': return 2; break;
        case '*': case '/': return 4; break;
        case '^': return 5; break;
        case '(': return 0; break;
        case '#': return -1; break;
        default: return 8;
    }
}

void push(char t){
    stack[++top]=t;
}
char pop(){
    if (top==-1)
        return '#';
    return stack[top--];
}
void main(){
    char t;
    printf("enter infix expr:");
    gets(infix);
    int i=0,j=0;
    push('#');
    while(infix[i]!='\0'){
        t=infix[i];
        if (t!='+'&&t!='-'&&t!='/'&&t!='*'&&t!='^'&&t!='('&&t!=')')
            postfix[j++] = t;
        else if (t == '(')
            push(t);
        else if (t == ')') {
            while (stack[top]!= '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while (stack_prec(stack[top])>= input_prec(t))
                postfix[j++] = pop();
            push(t);
        }
        i++;
    }
    while (stack[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("equivalent postfix:");
    printf("%s",postfix);
}
