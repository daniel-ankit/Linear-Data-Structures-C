#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Queue
{
    int first;
    int last;
    char *array[SIZE];
} Que;

int IsFull(Que q)
{
    if (q.last = SIZE - 1)
        return 1;
    return 0;
}

int IsEmpty(Que q)
{
    if (q.last == -1)
        return 1;
    return 0;
}

void enqueue(Que *Q, char C)
{
    if (Q->first == -1 && Q->last == -1)
    {
        (Q->first)++;
        (Q->last)++;
        Q->array[Q->last] = C;
    }
    else
    {
        Q->last++;
        Q->array[Q->last] = C;
    }
    printf("%c Queued.\n", C);
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

void peekat(Que Q, int index)
{
        if (IsEmpty(Q) || (index-1) > Q.last)
        {
            printf("Queue Underflow!\n");
        }
        else
            printf("%c\n", Q.array[index - 1]);
}

void dequeue(Que *Q)
{
    if (Q->last == -1)
        printf("Queue Undeflow!");
    else
    {
        printf("%c Dequeued.\n", Q->array[Q->first]);
        Q->first++;
    }
}

void dequeuechar(Que *Q, char C)
{
    if (Q->last == -1)
        printf("Queue Undeflow!");
    else
    {
        for (int i = 0; *(Q->array[i]) != '\0'; i++)
        {
            if (*(Q->array[i]) == C)
            {
                printf("%c Dequeued.\n", Q->array[i]);
                for (int j = (i + 1); *(Q->array[j]) != '\0'; j++)
                    Q->array[j] = Q->array[j + 1];
                Q->last--;
            }
            else
                printf("Element not Found!\n");
        }
    }
}

int main()
{
    Que Q;
    Q.first = -1;
    Q.last = -1;
    Q.array[SIZE] = (char *)malloc(SIZE * sizeof(char));
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    dequeue(&Q);
    dequeue(&Q);
    peek(Q);
    return 69;
}
