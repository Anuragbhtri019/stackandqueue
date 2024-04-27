#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define STACK_EMPTY '#'

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("\nStack Overflow.\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack underflow.\n");
        return STACK_EMPTY;
    } else {
        return stack[top--];
    }
}

int is_operator(char symbol) {
    return symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-';
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    }
    return 0;
}

void InfixToPrefix(char infix_exp[], char prefix_exp[]) {
    int i, j, pos = -1;
    char item, x, rev[MAX];

    // Reverse the infix expression and replace parentheses
    for (i = 0, j = strlen(infix_exp) - 1; i <= j; i++, j--) {
        item = infix_exp[i];
        infix_exp[i] = (infix_exp[j] == '(') ? ')' : (infix_exp[j] == ')') ? '(' : infix_exp[j];
        infix_exp[j] = (item == '(') ? ')' : (item == ')') ? '(' : item;
    }

    // Convert reversed infix to postfix
    for (i = 0; i < strlen(infix_exp); i++) {
        item = infix_exp[i];
        if (isalnum(item)) {
            rev[++pos] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while ((x = pop()) != '(') {
                rev[++pos] = x;
            }
        } else if (is_operator(item)) {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(item)) {
                rev[++pos] = pop();
            }
            push(item);
        }
    }

    while (top != -1) {
        rev[++pos] = pop();
    }
    rev[++pos] = '\0';

    // Reverse the postfix to get the prefix
    for (i = 0, j = strlen(rev) - 1; i < j; i++, j--) {
        item = rev[i];
        rev[i] = rev[j];
        rev[j] = item;
    }

    strcpy(prefix_exp, rev);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("\nEnter Infix expression : ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character if present
    InfixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}
