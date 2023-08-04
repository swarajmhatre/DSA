#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} NODE, *PNODE, **PPNODE;

class SinglyLL
{
private:
    PNODE First;
    int iSize;

   

public:
    SinglyLL();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
    int Count();
};

SinglyLL:: SinglyLL(){
        First = NULL;
        iSize = 0;
}

int SinglyLL::Count()
{
    return iSize;
}

void SinglyLL::InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iSize++;
}

void SinglyLL::InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn =new NODE;
    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else if (First->next == NULL)
    {
        First->next = newn;
    }
    else
    {
        PNODE temp = First;
        for (int i = 1; i < iSize; i++)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

void SinglyLL::InsertAtPos(int iNo, int iPos)
{

    if ((iPos < 1) || (iPos > iSize + 1))
    {
        printf("Invalid Input\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE temp = First;
        PNODE newn = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn =new NODE;
        newn->data = iNo;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

        iSize++;
    }
}

void SinglyLL::DeleteFirst()
{
    if (First == NULL)
    {
        printf("Nothing to delete...");
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First->next;
        delete temp;
    }
    iSize--;
}

void SinglyLL::DeleteLast()
{
    if (First == NULL)
    {
        printf("Nothing to delete...");
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        for (int i = 0; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}

void SinglyLL::DeleteAtPos(int iPos)
{
    if ((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid Input.\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        PNODE tempX = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;
        iSize--;
    }
}

void SinglyLL::Display()
{
    PNODE temp = First;
    printf("The Linked list is: ");
    for (int i = 1; i <= iSize; i++)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    SinglyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.Display();

    obj.InsertAtPos(101, 4);
    obj.Display();

    obj.DeleteAtPos(4);
    obj.Display();

    obj.DeleteFirst();
    obj.DeleteFirst();
    obj.Display();

    obj.DeleteLast();
    obj.DeleteLast();
    obj.Display();

    return 0;
}