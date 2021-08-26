#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int n);

void traversal(Node *head);

Node *insertatbeginning(Node *head, int data);

Node *insertatend(Node *head, int data);

Node *insertatindex(Node *head, int index);

Node *insertafterindex(Node *head, int index);

Node *deletefrombeginning(Node *head);

Node *deletefromend(Node *head);

Node *deletefromindex(Node *head, int index);

Node *delete (Node *head, int n);

Node *reverse(Node *head);

int main()
{
    int n, N;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *HEAD;
    HEAD = create(n);
    traversal(HEAD);
    
    printf("Enter data to be inserted at the beginning: ");
    scanf("%d", &N);
    HEAD=insertatbeginning(HEAD, N);
    traversal(HEAD);

    printf("Enter data to be inserted at the end: ");
    scanf("%d", &N);
    HEAD = insertatend(HEAD, N);
    traversal(HEAD);

    printf("Enter the index at which you wish to enter data: ");
    scanf("%d", &N);
    HEAD = insertatindex(HEAD, N);
    traversal(HEAD);

    printf("Enter th index after which you wish to enter data: ");
    scanf("%d", &N);
    HEAD = insertafterindex(HEAD, N);
    traversal(HEAD);
    
    HEAD=deletefrombeginning(HEAD);
    traversal(HEAD);

    printf("Enter the index you want to delete: ");
    scanf("%d", &N);
    HEAD=deletefromindex(HEAD, N-1);
    traversal(HEAD);

    HEAD=deletefromend(HEAD);
    traversal(HEAD);

    printf("Enter the element you wish to delete: ");
    scanf("%d", &N);
    HEAD = delete (HEAD, N);
    traversal(HEAD);

    HEAD = reverse(HEAD);
    traversal(HEAD);
    return 69;
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
    }
    return head;
}

void traversal(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

Node *insertatbeginning(Node *head, int data)
{
    Node *New_Node;
    New_Node = (Node *)malloc(sizeof(Node));
    New_Node->next = head;
    New_Node->data = data;
    return New_Node;
}

Node *insertatend(Node *head, int data)
{
    Node *New_Node = (Node *)malloc(sizeof(Node));
    New_Node->data = data;
    Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = New_Node;
    New_Node->next = NULL;
    return head;
}

Node *insertatindex(Node *head, int index)
{
    Node *New_Node, *p = head;
    New_Node = (Node *)malloc(sizeof(Node));
    for (int i = 0; i != index - 1; i++)
        p = p->next;
    printf("Enter the node data: ");
    scanf("%d", &New_Node->data);
    New_Node->next = p->next;
    p->next = New_Node;
    return head;
}

Node *insertafterindex(Node *head, int index)
{
    Node *New_Node, *p = head;
    New_Node = (Node *)malloc(sizeof(Node));
    for (int i = 0; i != index; i++)
        p = p->next;
    printf("Enter the node data: ");
    scanf("%d", &New_Node->data);
    New_Node->next = p->next;
    p->next = New_Node;
    return head;
}

Node *deletefrombeginning(Node *head)
{
    printf("After deleting first element of the list.\n");
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *deletefromend(Node *head)
{
    printf("Deleting last element of the list.\n");
    Node *p = (Node *)malloc(sizeof(Node)), *q = (Node *)malloc(sizeof(Node));
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

Node *deletefromindex(Node *head, int index)
{
    Node *p1 = (Node *)malloc(sizeof(Node));
    Node *p2 = (Node *)malloc(sizeof(Node));
    Node *p0 = (Node *)malloc(sizeof(Node));
    p0 = head;
    p1 = head;
    p2 = head;
    for (int i = 1; i < index - 1; i++)
        p0 = p0->next;
    for (int i = 1; i < index; i++)
        p1 = p1->next;
    for (int i = 1; i < index + 1; i++)
        p2 = p2->next;
    p0->next = p2;
    free(p1);
    return head;
}

Node *delete (Node *head, int n)
{
    Node *p, *q;
    p = head;
    q = head->next;
    while (p->data != n && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == n)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

Node *reverse(Node *head)
{
    Node *prev = NULL, *next = NULL, *current = head;
    while(current !=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
