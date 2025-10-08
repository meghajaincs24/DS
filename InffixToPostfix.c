#include <stdio.h>
#include <ctype.h>
#define SIZE 50

char stack[SIZE];
int top = -1;


void push(char elem) {
    stack[++top] = elem;
}


char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}


int pr(char symbol) {
    switch(symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}


int main() {
    char infix[SIZE], postfix[SIZE], ch, elem;
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {

            postfix[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        } else {
            while (top != -1 && pr(stack[top]) >= pr(ch)) {
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
