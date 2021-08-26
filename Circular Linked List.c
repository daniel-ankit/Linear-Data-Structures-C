#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void traversal(Node *head);

void traversal2(Node *head);

Node *create(int n);

Node *insertatbeginning(Node *head, int data);

Node *insertatend(Node *head, int data);

Node *insertatindex(Node *head, int data, int index);

Node *insertafterindex(Node *head, int data, int index);

Node *deletefromstart(Node *head);

Node *deletefromend(Node *head);

Node *deleteat(Node *head, int index);

Node *delete (Node *head, int data);

int main()
{
    int n, N, data;
    Node *HEAD, *first, *second, *third, *last;

    //printf("Enter the number of nodes: ");
    //scanf("%d", &n);
    //HEAD=create(n);

    first = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    last = (Node *)malloc(sizeof(Node));

    first->data = 11;
    first->next = second;
    second->data = 22;
    second->next = third;
    third->data = 33;
    third->next = last;
    last->data = 44;
    last->next = first;

    HEAD = first;
    traversal(HEAD);
    
    printf("Enter data to be inserted at the beginning: ");
    scanf("%d", &N);
    HEAD=insertatbeginning(HEAD, N);
    traversal(HEAD);

    printf("Enter data to be inserted at the end: ");
    scanf("%d", &N);
    HEAD=insertatend(HEAD, N);
    traversal(HEAD);

    printf("Enter the index at which you wish to enter data: ");
    scanf("%d", &N);
    printf("Enter the data at index %d: ", N);
    scanf("%d", &data);
    HEAD=insertatindex(HEAD, data, N);
    traversal(HEAD);

    HEAD = deletefromstart(HEAD);
    traversal(HEAD);

    HEAD = deletefromend(HEAD);
    traversal(HEAD);

    printf("Enter the index a you wish to delete: ");
    scanf("%d", &N);
    HEAD = deleteat(HEAD, N);
    traversal(HEAD);

    printf("Enter the element you wish to delete: ");
    scanf("%d", &N);
    HEAD = delete (HEAD, N);
    traversal(HEAD);

    return 69;
}

void traversal(Node *head)
{
    Node *ptr;
    ptr = head;
    while (ptr->next != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
    return;
}

void traversal2(Node *head)
{
    Node *p = head;
    do{
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

Node *create(int n)
{
    Node *ptr = NULL, *temp = NULL, *head = NULL;
    for (int i = 0; i < n; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        printf("Enter the data for node number %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL)
            head = temp;
        else
        {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
        temp->next = head;
    }
    return head;
}

Node *insertatbeginning(Node *head, int data)
{
    Node *New_Node, *first, *last;
    first = head->next;
    last = head;
    while (last->next != head)
    {
        last = last->next;
        first = first->next;
    }
    New_Node = (Node *)malloc(sizeof(Node));
    New_Node->next = first;
    New_Node->data = data;
    last->next = New_Node;
    return New_Node;
}

Node *insertatend(Node *head, int data)
{
    Node *New_Node, *first, *last;
    first = head->next;
    last = head;
    while (last->next != head)
    {
        last = last->next;
        first = first->next;
    }
    New_Node = (Node *)malloc(sizeof(Node));
    New_Node->next = first;
    New_Node->data = data;
    last->next = New_Node;
    return head;
}

Node *insertatindex(Node *head, int data, int index)
{
    Node *p = head, *New_Node;
    New_Node = (Node *)malloc(sizeof(Node));
    for (int i = 1; i != index - 1; i++)
        p = p->next;
    New_Node->data = data;
    New_Node->next = p->next;
    p->next = New_Node;
    return head;
}

Node *insertafterindex(Node *head, int data, int index)
{
    Node *p = head, *New_Node;
    New_Node = (Node *)malloc(sizeof(Node));
    for (int i = 0; i != index - 1; i++)
        p = p->next;
    New_Node->data = data;
    New_Node->next = p->next;
    p->next = New_Node;
    return head;
}

Node *deletefromstart(Node *head)
{
    Node *ptr = head, *p2 = head;
    while (p2->next != head)
        p2 = p2->next;
    head = head->next;
    p2->next = ptr->next;
    free(ptr);
    return head;
}

Node *deletefromend(Node *head)
{
    Node *previous = head, *current = head->next;
    while (current->next != head)
    {
        current = current->next;
        previous = previous->next;
    }
    previous->next = current->next;
    free(current);
    return head;
}

Node *deleteat(Node *head, int index)
{
    Node *current = head->next, *previous = head;
    for (int i = 1; i < index - 1; i++)
    {
        current = current->next;
        previous = previous->next;
    }
    previous->next = current->next;
    free(current);
    return head;
}

Node *delete (Node *head, int data)
{
    Node *ptr = head->next, *previous = head;
    while (ptr->data != data)
    {
        ptr = ptr->next;
        previous = previous->next;
    }
    previous->next = ptr->next;
    free(ptr);
    return head;
}
