#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} NODE, *PNODE, **PPNODE;

int Count(PNODE Head, PNODE Tail)
{
    int iCount = 0;

    if ((Head != NULL) && (Tail != NULL))
    {
        do
        {
            iCount++;
            Head = Head->next;
        } while (Head != Tail->next);
    }
    return iCount;
}

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo){
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    { // LL is empty
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;

        *Head = newn;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}


// Rule for inserting First: First tie up the newn to the old head properly and then change the tail and the head

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        newn->prev = *Tail;

        *Tail = newn;
    }
    (*Tail)->next = (*Head);
    (*Head)->prev = (*Tail);
}

void InsertAtPos(PPNODE Head, PPNODE Tail,int iNo,  int iPos)
{
    int iLength = Count(*Head, *Tail);
    PNODE newn = NULL;
    PNODE temp = *Head;

    if ((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid Input\n");
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(Head, Tail, iNo);
    }
    else if (iPos == iLength + 1)
    {
        InsertLast(Head, Tail, iNo);
    }
    else
    {
        for (int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        newn->prev = temp;
        newn->next = temp->next;

        temp->next = newn;
        newn->next->prev = newn;
    }
    // Rule: create a new node, join its end points and then join the other nodes to it
}

// Rule for inserting Last: Connect newn to the Tail First, cahnge tail to newn, then connect Tail and Head;

void DeleteFirst(PPNODE Head, PPNODE Tail)
{

    if ((*Head == NULL) && (*Tail == NULL))
    {
        printf("Nothing to delete...");
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
        *Head = (*Head)->next;
        free((*Tail)->next);

        (*Tail)->next = *Head;
        (*Head)->prev = *Tail;
    }
}
// Rule: Shift the Head, delete the node, connect Head and Tail

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    if ((*Head == NULL) && (*Tail == NULL))
    {
        printf("Nothing to delete...");
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
        *Tail = (*Tail)->prev;
        free((*Head)->prev);

        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}
// Rule: shift the Tail, delete the node, connect the Head and Tail

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos){
    int iLength = Count(*Head, *Tail);
    PNODE temp = *Head;

    if((iPos <1) || (iPos > iLength)){
        printf("Invalid Input\n");
        return;
    }
    else if(iPos == 1){
        DeleteFirst(Head, Tail);
    }
    else if(iPos == iLength){
        DeleteLast(Head, Tail);
    }
    else{
        for(int i =1; i < iPos-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}


void Display(PNODE Head, PNODE Tail)
{
    if ((Head != NULL) && (Tail != NULL))
    {
        do
        {
            printf("|%d|-> ", Head->data);
            Head = Head->next;
        } while (Head != Tail->next);
        printf("\n");
    }
    else
    {
        printf("Linked List is empty.");
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

    InsertLast(&First, &Last, 111);
    InsertLast(&First, &Last, 121);
    InsertLast(&First, &Last, 151);
    Display(First, Last);

    InsertAtPos(&First, &Last, 75, 4);
    Display(First, Last);
 
    DeleteAtPos(&First, &Last, 4);
    Display(First, Last);

    DeleteFirst(&First, &Last);
    DeleteFirst(&First, &Last);
    Display(First, Last);

    DeleteLast(&First, &Last);
    DeleteLast(&First, &Last);
    Display(First, Last);

    return 0;
}