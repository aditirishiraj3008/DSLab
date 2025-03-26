//infix to prefix expression
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char item)
{
    if (top >= MAX - 1)
        return;
    stack[++top] = item;
}
char pop()
{
    if (top < 0)
        return -1;
    return stack[top--];
}

int prec(char t)
{
    switch (t)
    {
    case '^':return 3;
    case '*':case '/':return 2;
    case '+':case '-':return 1;
    default:return 0;
    }
}

void reverse(char *str)
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int isAlphaorNum(char c)
{
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void main()
{
    char infix[MAX], prefix[MAX];
    printf("infix expr: ");
    gets(infix);
    char t, temp[2];
    int i, j = 0;
    reverse(infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        t = infix[i];
        if (isAlphaorNum(t))
            prefix[j++] = t;
        else if (t == ')')
            push(t);
        else if (t == '(')
            while ((temp[0] = pop()) != ')')
                prefix[j++] = temp[0];
        else
        {
            while (top > -1 && prec(stack[top]) > prec(t))
                prefix[j++] = pop();
            push(t);
        }
    }

    while (top > -1)
        prefix[j++] = pop();
    prefix[j] = '\0';

    reverse(prefix);
    printf("Prefix expr: %s\n", prefix);
}
