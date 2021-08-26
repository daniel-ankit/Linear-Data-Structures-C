#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

char peek()
{
    if (top != -1)
        return stack[top];
}

void push(char item)
{
    if (top >= SIZE - 1)
        printf("Stack Overflow.");
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char ch;
    if (top < 0)
    {
        printf("Stack Underflow.");
        exit(1);
    }
    else
    {
        ch = stack[top];
        top = top - 1;
        return ch;
    }
}

int isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int precedance(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixtopostfix(char infix[])
{
    int i, j;
    char postfix[SIZE];
    for (i = 0, j = -1; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
            postfix[++j] = infix[i];
        else if (infix[i] == '(')
            push('(');
        else if (infix[i] == ')')
        {
            int x = pop();
            while (top != -1 && x != '(')
            {
                postfix[++j] = x;
                x = pop();
            }
        }
        else
        {
            while (top != -1 && precedance(infix[i]) <= precedance(peek(stack)))
                postfix[++j] = pop(stack);
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[++j] = pop(stack);
    postfix[++j] = '\0';
    printf("%s", postfix);
}


int main()
{
    char exp[SIZE];
    gets(exp);
    infixtopostfix(exp);
    return 69;
}
