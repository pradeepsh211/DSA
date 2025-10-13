#include <stdio.h>
#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char elem) {
    stack[++top] = elem;
}

char pop() {
    return stack[top--];
}

int precedence(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;

    printf("Enter the infix Expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        } else {
            postfix[k++] = ch; // operand
        }
    }

    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("Postfix Expression = %s\n", postfix);

    return 0;
}
