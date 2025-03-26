#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE];

//if the stack is empty
int isEmpty() {
    return top == -1;
}

//push
void push(char item) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = item;
    } else {
        printf("Stack full\n");
    }
}

//pop
char pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack empty\n");
        return '\0';
    }
}

//if two matching pair
int isMatchingPair(char char1, char char2) {
    return (char1 == '(' && char2 == ')') ||
           (char1 == '{' && char2 == '}') ||
           (char1 == '[' && char2 == ']');
}

//if balanced parentheses
int Balanced(char expr[]) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (isEmpty()) {
                return 0; // Not matching
            }
            char poppedChar = pop();
            if (!isMatchingPair(poppedChar, expr[i])) {
                return 0; // Not matched
            }
        }
    }
    return isEmpty(); // Stack should be empty if balanced
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter expression: ");
    scanf("%s", expr);
    if (Balanced(expr))
        printf("Parentheses balanced\n");
    else
        printf("Parentheses not balanced\n");
    return 0;
}
