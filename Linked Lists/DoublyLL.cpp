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
        cout << "NULL <=> ";
        for (int i = 1; i <= iSize; i++)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    int Count()
    {
        return iSize;
    }
};

class DoublyLL : public LinkedList
{
public:
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

void DoublyLL::InsertFirst(int iNo)
{
    PNODE newn = new NODE(iNo);
    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iSize++;
}
void DoublyLL::InsertLast(int iNo)
{
    PNODE newn = new NODE(iNo);
    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;
        for (int i = 1; i < iSize; i++)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iSize++;
}
void DoublyLL::InsertAtPos(int iNo, int iPos)
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
void DoublyLL ::DeleteFirst()
{
    if (First == nullptr)
    {
        cout << "Nothing to delete...\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    iSize--;
}
void DoublyLL ::DeleteLast()
{
    if (First == NULL)
    {
        cout << "Nothing to delete\n";
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
        for (int i = 1; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}
void DoublyLL ::DeleteAtPos(int iPos)
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
    DoublyLL obj;
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