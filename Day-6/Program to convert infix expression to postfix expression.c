#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[100];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int main() {
    char infix[100], postfix[100];
    int i, k = 0;
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; 
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
