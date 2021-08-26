#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int index;
    int *array;

}stack;

stack *create(int n);

int isFull(stack *S);

int isEmpty(stack *S);

void peek(struct stack* S);

void push(stack *S, int n);

void pop(stack *S);

void peekat(stack *S);

void traversal(stack *S);

int main()
{
    int n, data;
    stack *S;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    S=create(n);
    printf("Enter the %d stack elements: ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &data);
        push(S, data);
    }
    peek(S);
    pop(S);
    peek(S);
    pop(S);
    peek(S);
    push(S, 66);
    push(S, 77); 
    peek(S);
    push(S, 88);
    peekat(S);
    traversal(S);
    return 69;
}

stack *create(int n)
{
    stack *S1 = (stack*)malloc(sizeof(stack));
    S1->size = n;
    S1->index = -1;
    S1->array = (int *)malloc(S1->size * sizeof(int));
    return S1;
}

void traversal(stack *S)
{
    printf("Elements in the stack are: ");
    for(int i=0; i<=S->index; i++)
    printf("%d ", S->array[i]);
    return;
}

int isFull(stack *S)
{
    return S->index == S->size-1;
}

int isEmpty(stack *S)
{
    if (S->index == -1)
    return 1;
    else return 0;
}

void peek(struct stack* S)
{
    if (isEmpty(S))
        printf("Stack is empty, dude!\n\n");
    else printf("Latest element now is: %d.\n\n", S->array[S->index]);
}

void push(stack *S, int n)
{
    if(isFull(S))
    printf("Cannot insert. Stack is full!\n\n");
    else{
    S->array[S->index+1] = n;
    S->index++;
    printf("%d is pushed in the stack.\n\n", n);
    }
}

void pop(stack *S)
{
    if(isEmpty(S))
    printf("Cannot remove elements from Empty Stack!\n\n");
    else{
    S->array[S->index--];
    printf("%d is popped out from stack.\n\n", S->array[S->index+1]);
    }
}

void peekat(stack *S)
{
    int at;
    printf("Enter the index you want to peek: ");
    scanf("%d", &at);
    if(at<=S->index)
    printf("%d element of he stack is %d.\n", at, S->array[at-1]);
    else printf("No element found!\n");
}
