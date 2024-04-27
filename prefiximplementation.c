#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack implementation
#define MAX_SIZE 100  // Define the maximum size of the stack

struct Stack {
    int top;
    double items[MAX_SIZE];
};

void push(struct Stack* stack, double value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = value;
    } else {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

double pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

// Function to evaluate a prefix expression
double evaluatePrefix(const char* expr) {
    struct Stack stack;
    stack.top = -1;

    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        if (isspace(expr[i])) { // Skip spaces
            continue;
        } else if (isdigit(expr[i])) {
            int num = 0;
            int base = 1;
            // Read the whole number
            while (i >= 0 && isdigit(expr[i])) {
                num = num + (expr[i] - '0') * base;
                base *= 10;
                i--;
            }
            i++; // Adjust the index after the loop
            push(&stack, num);
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            double operand1 = pop(&stack);
            double operand2 = pop(&stack);
            switch (expr[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&stack, operand1 / operand2);
                    } else {
                        fprintf(stderr, "Division by zero error\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
            }
        } else {
            fprintf(stderr, "Invalid character found: %c\n", expr[i]);
            exit(EXIT_FAILURE);
        }
    }

    return pop(&stack);
}

int main() {
    char expr[100];
    printf("Enter a prefix expression: ");
    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    // Remove newline character if present
    expr[strcspn(expr, "\n")] = '\0';

    double result = evaluatePrefix(expr);
    printf("Result of the prefix expression: %.2lf\n", result);
    return 0;
}
