#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100
#define count 0

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

int IsEmpty(Node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

Node *Last(Node *head)
{
    Node *last = NULL;
    if (head = NULL)
        return last;
    while (head->next != NULL)
    {
        head = head->next;
    }
    last = head;
    return last;
}

Node *enQueue(Node *head, char data)
{
    Node *New_Node = (Node *)malloc(sizeof(Node));
    New_Node->data = data;
    if (head == NULL)
    {
        head = New_Node;
        New_Node->next = NULL;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = New_Node;
        New_Node->next = NULL;
    }
    printf("%c Enqueued.\n", data);
    return head;
}

void peek(Node *head)
{
    if (head == NULL)
        printf("Stack Underflow!\n");
    else
        printf("%c\n", head->data);
}

void peekat(Node *head, int index)
{
    if(index>0)
    {
    for (int i = 0; i < index-1; i++)
        head = head->next;
    printf("Element at %d index is: %c.\n", index, head->data);
    }
}

Node *deQueue(Node *head)
{
    if(head == NULL)
        printf("Queue Underflow!\n");
    else 
    {
        printf("%c deQueued.\n", head->data);
        head=head->next;
    }
    return head;
}

int main()
{
    Node *HEAD = NULL;
    HEAD = enQueue(HEAD, 'A');
    HEAD = deQueue(HEAD);
    HEAD = enQueue(HEAD, 'B');
    HEAD = enQueue(HEAD, 'C');
    HEAD = deQueue(HEAD);
    HEAD = enQueue(HEAD, 'D');
    HEAD = enQueue(HEAD, 'E');
    peekat(HEAD, 0);
    peekat(HEAD, 1);
    peekat(HEAD, 2);
    peekat(HEAD, 3);
    peekat(HEAD, 4);
    peek(HEAD);
    peekat(HEAD, 5);
    return 69;
}
