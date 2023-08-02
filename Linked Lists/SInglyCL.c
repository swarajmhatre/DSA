#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} NODE, *PNODE, **PPNODE;

int Count(PNODE Head, PNODE Tail)
{
    PNODE temp = Head;
    int iCnt = 0;
    if ((Head != NULL) && (Tail != NULL))
    {
        do
        {
            iCnt++;
            temp = temp->next;
        } while (temp != Tail->next);
    }
    return iCnt;
}

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head;
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
    int iLength = Count(*Head, *Tail);
    PNODE newn = NULL;
    PNODE temp = NULL;
    if ((iPos < 1) || (iPos > (iLength + 1)))
    {
        printf("Invalid Input\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(Head, Tail, iNo);
    }
    else if (iPos == iLength+1)
    {
        InsertLast(Head, Tail, iNo);
    }
    else
    {
        temp = *Head;

        for (int i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if ((*Head == NULL) && (*Tail == NULL))
    {
        printf("Nothing to Delete...");
        return;
    }
    else if ((*Head == *Tail))
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = NULL;
    if ((*Head == NULL) && (*Tail == NULL))
    {
        printf("NOthing to delete...\n");
        return;
    }
    else if (*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        temp = *Head;
        while (temp->next != *Tail)
        {
            temp = temp->next;
        }
        free(*Tail);
        *Tail = temp;
        (*Tail)->next= *Head;
    }
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
    int iLength = Count(*Head, *Tail);
    PNODE temp = NULL;
    PNODE tempX = NULL;

    if ((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Input\n");
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst(Head, Tail);
    }
    else if (iPos == iLength)
    {
        DeleteLast(Head, Tail);
    }
    else
    {
        temp = *Head;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
    }
}

void Display(PNODE Head, PNODE Tail)
{
    PNODE temp = Head;
    if ((Head != NULL) && (Tail != NULL))
    {
        do
        {
            printf("|%d|=>", temp->data);
            temp = temp->next;
        } while (temp != Tail->next);
        printf("\n");
    }
    else
    {
        printf("The Linked List is empty");
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;

    InsertFirst(&First, &Last, 51);
    InsertFirst(&First, &Last, 21);
    InsertFirst(&First, &Last, 11);
    Display(First, Last);
    printf("Number of elements: %d \n", Count(First, Last));

    InsertLast(&First, &Last, 121);
    InsertLast(&First, &Last, 151);
    Display(First, Last);
    printf("Number of elements: %d \n", Count(First, Last));

    InsertAtPos(&First, &Last, 221, 4);

    Display(First, Last);
    printf("Number of elements: %d \n", Count(First, Last));

    DeleteAtPos(&First, &Last, 4);
    Display(First, Last);
    printf("Number of elements: %d \n", Count(First, Last));

    DeleteFirst(&First, &Last);
    Display(First, Last);
    printf("Number of elements: %d \n", Count(First, Last));

    DeleteLast(&First, &Last);
    Display(First, Last);
    printf("Number of elements: %d \n", Count(First, Last));
    return 0;
}