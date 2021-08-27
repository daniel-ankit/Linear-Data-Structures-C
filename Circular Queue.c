#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Queue
{
    int first;
    int last;
    char *array[SIZE];
} Que;

int IsFull(Que Q)
{
    if ((Q.last == SIZE - 1 && Q.first == 0) || (Q.last + 1) % SIZE == Q.first)
        return 1;
    return 0;
}

int IsEmpty(Que Q)
{
    if (Q.last == -1 && Q.first == -1)
        return 1;
    return 0;
}

void enQueue(Que *Q, char C)
{
    if (Q->first == -1 && Q->last == -1)
    {
        (Q->first)++;
        (Q->last)++;
        Q->array[Q->last] = C;
        printf("%c Queued.\n", C);
    }
    else if (IsFull(*Q))
        printf("Queue Overflow!\n");
    else
    {
        Q->last = (Q->last + 1) % SIZE;
        Q->array[Q->last] = C;
        printf("%c Queued.\n", C);
    }
}

void peek(Que Q)
{
    if (IsEmpty(Q))
    {
        printf("Queue Underflow!\n");
    }
    else
        printf("%c\n", Q.array[Q.first]);
}

void deQueue(Que *Q)
{
    if (IsEmpty(*Q))
        printf("Queue Undeflow!");
    else
    {
        printf("%c DeQueued.\n", Q->array[Q->first]);
        Q->first = (Q->first + 1) % SIZE;
    }
}

int main()
{
    Que Q;
    Q.first = -1;
    Q.last = -1;
    Q.array[SIZE] = (char *)malloc(SIZE * sizeof(char));
    printf("%d\n", IsEmpty(Q));
    enQueue(&Q, 'A');
    enQueue(&Q, 'B');
    printf("%d\n", IsEmpty(Q));
    enQueue(&Q, 'C');
    enQueue(&Q, 'D');
    enQueue(&Q, 'E');
    printf("%d\n", IsFull(Q));
    deQueue(&Q);
    deQueue(&Q);
    peek(Q);
    enQueue(&Q, 'F');
    enQueue(&Q, 'G');
    enQueue(&Q, 'H');
    printf("%d\n", IsFull(Q));
    peek(Q);
    return 69;
}
