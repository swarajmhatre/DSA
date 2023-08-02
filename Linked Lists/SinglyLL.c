#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//________________________________________This is the code which does all the operation on a Singly Linked List__________________________________________
//______________________________________________________________Feel free to contribute__________________________________________________________________
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Node Structure
typedef struct Node
{
    int data;
    struct Node *next;
} NODE, *PNODE, **PPNODE;

// Count all nodes in the Linked List
int Count(PNODE Head)
{
    int iCnt = 0;
    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

//Insert a new node at first position
void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

//Insert a new node at last position
void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}
 
//Insert a new node at the desired position
void InsertAtPos(PPNODE Head, int No, int iPos)
{
    int iLength = Count(*Head);

    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if ((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid Input.\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(Head, No);
    }
    else if (iPos == (iLength + 1))
    {
        InsertLast(Head, No);
    }
    else
    {
        PNODE temp = *Head;
        newn->data = No;
        newn->next = NULL;

        for (int i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

//Delete a node from the last position
void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    if (*Head == NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        return;
    }
    else
    {
        *Head = (*Head)->next;
        free(temp);
    }
}

//Delete a node from the first position
void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL){
        printf("Nothing to Delete.\n");
        return;
    }
    else if((*Head)->next == NULL ){
        free(*Head);
        return;
    }   
    else{
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    
}

//Delete a node from the desired position
void DeleteAtPos(PPNODE Head, int iPos)
{
    int iLength = Count(*Head);
    PNODE temp = *Head;
    PNODE tempX = NULL;

    if ((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Input\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if (iPos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
    }
}

//Display the Linked Lists
void Display(PNODE Head)
{
    printf("Elements of Linked List are: \n");
    while (Head != NULL)
    {
        printf("|%d| -> ", Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 111);
    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    InsertLast(&First, 121);
    InsertLast(&First, 151);

    Display(First);

    DeleteFirst(&First);
    Display(First);

    DeleteLast(&First);
    Display(First);

    DeleteAtPos(&First, 2);
    Display(First);


    printf("Count is: %d", Count(First));

    return 0;
}