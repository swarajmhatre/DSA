#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//________________________________________This is the code which does all the operation on a Doubly Linked List__________________________________________
//______________________________________________________________Feel free to contribute__________________________________________________________________
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Node Structure
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} NODE, *PNODE, **PPNODE;


// Count all nodes in the Linked List
int Count(PNODE Head)
{
    int iCnt = 0;
    PNODE temp = Head;

    while (temp->next != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

//Insert a new node at first position
void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        (*Head)->prev = newn;
        newn->next = *Head;
        *Head = newn;
    }
}

//Insert a new node at Last position
void InsertLast(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->prev = NULL;
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
        newn->prev = temp;
    }
}

//Insert a new node at the desired position
void InsertAtPos(PPNODE Head, int iNo, int iPos){
    int iLength = Count(*Head);
    PNODE newn = NULL;
    PNODE temp = *Head;

    if((iPos<1)|| (iPos> iLength+1)){
        printf("\nInvalid Input.\n");
        return;
    }
    if(iPos == 1){
        InsertFirst(Head, iNo);
    }
    else if(iPos == (iLength+1)){
        InsertLast(Head, iNo);
    }
    else{
        for(int i =1; i<iPos-1; i++){
            temp = temp->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

//Delete a node from first position
void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if (*Head == NULL)
    {
        printf("Nothing to Delete\n");
        return;
    }
    else if(((*Head)->next == NULL)){
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        (*Head)->prev = NULL;
        free(temp);
    }
}

//Delete a node from Last position
void DeleteLast(PPNODE Head){
    PNODE temp = *Head;

    if(*Head == NULL){
        printf("Nothing to Delete\n");
        return;
    }
    else if((*Head)->next == NULL){
        free(*Head);
        *Head = NULL;
    }
    else{
        while ((temp->next->next) != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

//Delete a node at the desired position
void DeleteAtPos(PPNODE Head, int iPos){
    int iLength = Count(*Head);
    PNODE temp = *Head;
    PNODE tempX = NULL;

    if((iPos<1)|| (iPos>iLength)){
        printf("Invalid Input\n");
        return;
    }

    if (iPos == 1)
    {
       DeleteFirst(Head);
    }
    else if(iPos == iLength){
        DeleteLast(Head);
    }
    else{
         for(int i=1; i< iPos-1; i++){
            temp = temp->next;
         }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

//Display the entire Linked List
void Display(PNODE Head)
{
    PNODE temp = Head;
    printf("The elements in the Linked List are: ");
    while (temp != NULL)
    {
        printf("|%d|-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    Display(First);
    printf("Number of elements: %d \n", Count(First));

    InsertLast(&First, 121);
    InsertLast(&First, 151);
    Display(First);
    printf("Number of elements: %d \n", Count(First));


    InsertAtPos(&First, 221,4);

    Display(First);
    printf("Number of elements: %d \n", Count(First));

    DeleteAtPos(&First, 4);
    Display(First);
    printf("Number of elements: %d \n", Count(First));

    DeleteFirst(&First);
    Display(First);
    printf("Number of elements: %d \n", Count(First));

    DeleteLast(&First);
    Display(First);
    printf("Number of elements: %d \n", Count(First));

    return 0;
}