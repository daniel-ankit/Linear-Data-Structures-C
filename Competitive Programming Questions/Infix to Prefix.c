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

void infixtoprefix(char infix[])
{
    int i, j;
    char prefix[SIZE], X;
    for (i = 0, j = -1; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
            prefix[++j] = infix[i];
        else if (infix[i] == '(')
            push('(');
        else if (infix[i] == ')')
        {
            while (infix[i] != '(')
            {
                prefix[++j] = infix[i];
                i++;
            }
        }
        else if (isOperator(infix[i]))
        {
            if (top == -1)
                push(infix[i]);
            else
            {
                if (precedance(infix[i] > precedance(peek())))
                    push(infix[i]);
                else if (precedance(infix[i] == precedance(peek())) && infix[i] == '^')
                {
                    while ((precedance(infix[i] == precedance(peek())) && infix[i] == '^')!=1)
                    {
                        prefix[++j] = pop();
                        push(infix[i]);
                    }
                }
                else if (precedance(infix[i] == precedance(peek())))
                    push(infix[i]);
                else if (precedance(infix[i] < precedance(peek())))
                {
                    while(top!=-1 && (precedance(infix[i] < precedance(peek()))))
                    {
                    prefix[++j] = pop();
                    push(infix[i]);
                    }
                }
            }
        }
    }
    while (top != -1)
        prefix[++j] = pop(stack);
    prefix[++j] = '\0';
    printf("%s", strrev(prefix));
}

int main()
{
    char exp[SIZE];
    gets(exp);
    infixtoprefix(strrev(exp));
    return 69;
}
