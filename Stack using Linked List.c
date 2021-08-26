#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    struct stack *next;
    char data;
} stack;

void traversal(stack *head)

int IsEmpty(stack *head)

int IsFull(stack *head)

stack *push(stack *head, char data)

void peek(stack *head)

stack *pop(stack *head)

int main()
{
    stack *HEAD = NULL;
    HEAD = push(HEAD, 'A');
    HEAD = push(HEAD, 'B');
    HEAD = push(HEAD, 'C');
    HEAD = push(HEAD, 'D');
    HEAD = push(HEAD, 'E');
    traversal(HEAD);
    peek(HEAD);
    HEAD = pop(HEAD);
    HEAD = pop(HEAD);
    peek(HEAD);
    return 69;
}

void traversal(stack *head)
{
    while (head != NULL)
    {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

int IsEmpty(stack *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int IsFull(stack *head)
{
    stack *New_Node = (stack *)malloc(sizeof(stack));
    if (New_Node == NULL)
        return 1;
    else
        return 0;
}

stack *push(stack *head, char data)
{
    if (!IsFull(head))
    {
        stack *New_Node = (stack *)malloc(sizeof(stack));
        New_Node->data = data;
        New_Node->next = head;
        printf("Pushed %c.\n", data);
        head = New_Node;
        return head;
    }
    else
    {
        printf("Stack Overflow!\n");
        return head;
    }
}

void peek(stack *head)
{
    if (!IsEmpty(head))
        printf("%c\n", head->data);
    else
        printf("Empty stack!\n");
}

stack *pop(stack *head)
{
    if (IsEmpty(head))
    {
        printf("Stack Underflow!\n");
        return head;
    }
    else
    {
        stack *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }
}
