//prefix to infix expression
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *item)
{
    if (top >= MAX - 1)
        return;
    strcpy(stack[++top], item);
}

char *pop()
{
    if (top < 0)
        return NULL;
    return stack[top--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isAlphaorNum(char c)
{
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void main()
{
    char prefix[MAX];
    printf("Enter prefix expr: ");
    gets(prefix);
    char temp[MAX];
    for (int i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (isAlphaorNum(prefix[i]))
        {
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }
        else if (isOperator(prefix[i]))
        {
            char op1[MAX], op2[MAX], result[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(result, "(%s%c%s)", op1, prefix[i], op2);
            push(result);
        }
    }
    printf("Infix expr: %s\n", stack[top]);
}
