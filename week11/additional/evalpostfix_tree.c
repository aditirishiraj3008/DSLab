//Write a program to create a tree for a postfix expression and evaluate it.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluate(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (!isOperator(root->data)) {
        return root->data - '0'; // Convert char to int
    }

    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    switch (root->data) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return leftEval / rightEval;
    }
    return 0;
}

struct TreeNode* buildTree(char* postfix) {
    struct TreeNode* stack[100]; // Stack to hold tree nodes
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];

        // If the character is an operand, create a new node and push to the stack
        if (isdigit(c)) {
            stack[++top] = createNode(c);
        } else if (isOperator(c)) {
            // Pop two nodes for the operator
            struct TreeNode* right = stack[top--];
            struct TreeNode* left = stack[top--];

            struct TreeNode* operatorNode = createNode(c);
            operatorNode->left = left;   // Set left child
            operatorNode->right = right;  // Set right child

            stack[++top] = operatorNode;
        }
    }

    return stack[top];
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    struct TreeNode* root = buildTree(postfix);
    int result = evaluate(root);

    printf("The result of the expression is: %d\n", result);

    return 0;
}
