#include <iostream>
using namespace std;

typedef class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int iNo)
    {
        data = iNo;
        next = NULL;
        prev = NULL;
    }
} NODE, *PNODE;

class LinkedList
{
protected:
    PNODE First;
    int iSize;

public:
    LinkedList()
    {
        First = NULL;
        iSize = 0;
    }
    virtual void InsertFirst(int iNo) = 0;
    virtual void InsertLast(int iNo) = 0;
    virtual void InsertAtPos(int iNo, int iPos) = 0;
    virtual void DeleteFirst() = 0;
    virtual void DeleteLast() = 0;
    virtual void DeleteAtPos(int iPos) = 0;

    void Display()
    {
        PNODE temp = First;
        cout << "\nThe elements of the Linked List Are: ";
        cout << "<=> ";
        for (int i = 1; i <= iSize; i++)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
    }

    int Count()
    {
        return iSize;
    }
};

class DoublyCL : public LinkedList
{
private:
    PNODE Last;

public:
    DoublyCL();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};
DoublyCL::DoublyCL()
{
    Last = NULL;
}
void DoublyCL::InsertFirst(int iNo)
{
    PNODE newn = new Node(iNo);
    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    iSize++;
};
void DoublyCL ::InsertLast(int iNo)
{
    PNODE newn = new NODE(iNo);
    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;
    iSize++;
}
void DoublyCL ::InsertAtPos(int iNo, int iPos)
{
    if ((iPos < 1) && (iPos > iSize + 1))
    {
        cout << "\nInvalid Input!";
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
        PNODE newn = new NODE(iNo);
        PNODE temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        newn->prev = temp;
        newn->next->prev = newn;
        iSize++;
    }
}
void DoublyCL ::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "\nNothing to delete!";
        return;
    }
    if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }
    iSize--;
}
void DoublyCL ::DeleteLast()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "\nInvalid Input!";
        return;
    }
    if (First == Last)
    {
        delete Last;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
    iSize--;
}
void DoublyCL ::DeleteAtPos(int iPos)
{
    if ((iPos < 1) && (iPos > iSize))
    {
        cout << "\nInvalid Input!";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize + 1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iSize--;
    }
}

int main()
{
    DoublyCL obj;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(111);
    obj.InsertLast(121);
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