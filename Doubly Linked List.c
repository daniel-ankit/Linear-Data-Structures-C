#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

void traversal(Node *head)
{
    printf("Forward Traversal: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

void reversetraversal(Node *head)
{
    printf("Reverse Traversal: ");
    Node *ptr=head;
    while (ptr->next != NULL)
        ptr=ptr->next;
    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n\n");
    return;
}

Node *insertatbeginning(Node *head, int data)
{
    Node *New_Node;
    New_Node = (Node *)malloc(sizeof(Node));
    New_Node->next = head;
    head = New_Node;
    New_Node->prev = NULL;
    (head->next)->prev=New_Node;
    New_Node->data = data;
    return head;
}

Node *insertatend(Node *head, int data)
{
    Node *New_Node, *ptr = head;
    New_Node = (Node *)malloc(sizeof(Node));
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = New_Node;
    New_Node->data = data;
    New_Node->next = NULL;
    New_Node->prev = ptr;
    return head;
}

Node *insertatindex(Node *head, int data, int index)
{
    Node *New_Node = (Node *)malloc(sizeof(Node)), *ptr = head;
    for (int i = 1; i < index - 1; i++)
        ptr = ptr->next;
    New_Node->next= ptr->next;
    (ptr->next)->prev = New_Node;
    ptr->next = New_Node;
    New_Node->data = data;
    New_Node->prev = ptr;
    return head;
}

Node *insertafterindex(Node *head, int data, int index)
{
        Node *New_Node = (Node *)malloc(sizeof(Node)), *ptr = head;
    for (int i = 1; i < index; i++)
        ptr = ptr->next;
    New_Node->next= ptr->next;
    (ptr->next)->prev = New_Node;
    ptr->next = New_Node;
    New_Node->data = data;
    New_Node->prev = ptr;
    return head;
}

Node *deletefrombeginning(Node *head)
{
    Node *ptr = head;
    head = ptr->next;
    (ptr->next)->prev=NULL;
    free(ptr);
    return head;
}

Node *deletefromend(Node *head)
{
    Node *ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    (ptr->prev)->next=NULL;
    free(ptr);
    return head;
}

Node *deleteatindex(Node *head, int index)
{
    Node *ptr=head;
    for(int i=1; i<index; i++)
        ptr=ptr->next;
    (ptr->prev)->next=ptr->next;
    (ptr->next)->prev = ptr->prev;
    free(ptr);
    return head;
}

Node *delete(Node *head, int data)
{
    Node *ptr=head;
    while(ptr->data!=data)
    ptr=ptr->next;
    (ptr->prev)->next=ptr->next;
    (ptr->next)->prev = ptr->prev;
    free(ptr);
    return head;
}

int main()
{
    int n, N, data;
    Node *HEAD, *first, *second, *third, *fourth, *last;

    first = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));
    last = (Node *)malloc(sizeof(Node));

    first->prev = NULL;
    first->data = 15;
    first->next = second;

    second->prev = first;
    second->data = 30;
    second->next = third;

    third->prev = second;
    third->data = 45;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 60;
    fourth->next = last;

    last->prev = fourth;
    last->data = 75;
    last->next = NULL;

    printf("Initial Linked list:\n");
    HEAD = first;
    traversal(HEAD);
    reversetraversal(HEAD);

    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d", &N);
    HEAD = insertatbeginning(HEAD, N);
    printf("\nFinal Linked list:\n");
    traversal(HEAD);
    reversetraversal(HEAD);

    printf("Enter the data you want to insert at the end: ");
    scanf("%d", &N);
    HEAD = insertatend(HEAD, N);
    printf("\nFinal Linked list:\n");
    traversal(HEAD);
    reversetraversal(HEAD);
    
    printf("Enter the index at which you wish to enter data: ");
    scanf("%d", &N);
    printf("Enter the data at index %d: ", N);
    scanf("%d", &data);
    HEAD = insertatindex(HEAD, data, N);
    printf("\nFinal Linked list:\n");
    traversal(HEAD);
    reversetraversal(HEAD);
    
    printf("Enter the index after which you wish to enter data: ");
    scanf("%d", &N);
    printf("Enter the data at index %d: ", N);
    scanf("%d", &data);
    HEAD = insertafterindex(HEAD, data, N);
    printf("\nFinal Linked list:\n");
    traversal(HEAD);
    reversetraversal(HEAD);
    
    printf("\nAfter deleting first element of the linked list: \n");
    HEAD=deletefrombeginning(HEAD);
    traversal(HEAD);
    reversetraversal(HEAD);
    
    printf("\nAfter deleting last element of the linked list: \n");
    HEAD=deletefromend(HEAD);
    traversal(HEAD);
    reversetraversal(HEAD);

    printf("Enter the index you wish to delete: ");
    scanf("%d", &N);
    HEAD = deleteatindex(HEAD, N);
    printf("\nFinal Linked list:\n");
    traversal(HEAD);
    reversetraversal(HEAD);

    printf("Enter the element you wish to delete: ");
    scanf("%d", &data);
    HEAD = delete(HEAD, data);
    printf("\nFinal Linked list:\n");
    traversal(HEAD);
    reversetraversal(HEAD);

    return 69;
}
