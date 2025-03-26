//postfix to infix expression
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_EXPR_LEN 200

char stack[MAX_SIZE][MAX_EXPR_LEN];
int top = -1;

void push(char* item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack[++top], item);
}

char* pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void main() {
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    gets(postfix);
    char op1[MAX_EXPR_LEN], op2[MAX_EXPR_LEN], temp[MAX_EXPR_LEN];
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        } else {
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);
            push(temp);
        }
    }
    printf("Equivalent infix expression: %s\n", pop());
}
