#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//________________________________________This is the code which does all the operation on a Linked List__________________________________________
//______________________________________________________________Feel free to contribute__________________________________________________________________
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

    int Count()
    {
        return iSize;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Doubly Circular Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class DoublyCL : public LinkedList
{
private:
    PNODE Last;

public:
    DoublyCL();
    ~DoublyCL();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};
DoublyCL::DoublyCL()
{
    Last = NULL;
}

DoublyCL::~DoublyCL()
{
    PNODE temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

void DoublyCL ::Display()
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Doublu Linear Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class DoublyLL : public LinkedList
{
public:
    ~DoublyLL();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

DoublyLL::~DoublyLL()
{
    PNODE temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

void DoublyLL ::Display()
{
    PNODE temp = First;
    cout << "\nThe elements of the Linked List Are: ";
    cout << "NULL <=> ";
    for (int i = 1; i <= iSize; i++)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL ";
}

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Singly Circular Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SinglyCL : public LinkedList
{
private:
    PNODE Last;

public:
    SinglyCL();
    ~SinglyCL();

    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

SinglyCL::SinglyCL()
{
    Last = NULL;
}

SinglyCL::~SinglyCL()
{
    PNODE temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

void SinglyCL::Display()
{
    PNODE temp = First;
    printf("\nThe Linked list is: ");
    for (int i = 1; i <= iSize; i++)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
}

void SinglyCL ::InsertFirst(int iNo)
{
    PNODE newn = new NODE(iNo);

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
    iSize++;
}

void SinglyCL ::InsertLast(int iNo)
{
    PNODE newn = new NODE(iNo);
    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        Last->next = newn;
        Last = newn;
    }
    iSize++;
}

void SinglyCL ::InsertAtPos(int iNo, int iPos)
{
    if ((iPos < 1) || (iPos > iSize + 1))
    {
        cout << "Invalid Input\n";
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
        for (int i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

void SinglyCL::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "Nothing to Delete...\n";
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iSize--;
}

void SinglyCL::DeleteLast()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "Nothing to Delete...\n";
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE temp = First;
        for (int i = 1; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = First;
        delete Last;
        Last = temp;
    }
    iSize--;
}

void SinglyCL ::DeleteAtPos(int iPos)
{
    if ((iPos < 1) || (iPos > iSize))
    {
        cout << "Invalid Input";
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//_______________________________________________________________________Singly Linear Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SinglyLL : public LinkedList
{
public:
    ~SinglyLL();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

SinglyLL::~SinglyLL()
{
    PNODE temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
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

    newn = new NODE;
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
        newn = new NODE;
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
    DoublyCL dcobj;
    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);
    dcobj.Display();

    dcobj.InsertLast(111);
    dcobj.InsertLast(121);
    dcobj.Display();

    dcobj.InsertAtPos(101, 4);
    dcobj.Display();

    dcobj.DeleteAtPos(4);
    dcobj.Display();

    dcobj.DeleteFirst();
    dcobj.DeleteFirst();
    dcobj.Display();

    dcobj.DeleteLast();
    dcobj.DeleteLast();
    dcobj.Display();

    cout << endl;
    cout << endl;

    DoublyLL dlobj;
    dlobj.InsertFirst(51);
    dlobj.InsertFirst(21);
    dlobj.InsertFirst(11);
    dlobj.Display();

    dlobj.InsertLast(111);
    dlobj.InsertLast(121);
    dlobj.Display();

    dlobj.InsertAtPos(101, 4);
    dlobj.Display();

    dlobj.DeleteAtPos(4);
    dlobj.Display();

    dlobj.DeleteFirst();
    dlobj.DeleteFirst();
    dlobj.Display();

    dlobj.DeleteLast();
    dlobj.DeleteLast();
    dlobj.Display();

    cout << endl;
    cout << endl;

    SinglyCL scobj;
    scobj.InsertFirst(51);
    scobj.InsertFirst(21);
    scobj.InsertFirst(11);
    scobj.Display();

    scobj.InsertLast(111);
    scobj.InsertLast(121);
    scobj.Display();

    scobj.InsertAtPos(101, 4);
    scobj.Display();

    scobj.DeleteAtPos(4);
    scobj.Display();

    scobj.DeleteFirst();
    scobj.DeleteFirst();
    scobj.Display();

    scobj.DeleteLast();
    scobj.DeleteLast();
    scobj.Display();

    cout << endl;
    cout << endl;

    SinglyLL slobj;
    slobj.InsertFirst(51);
    slobj.InsertFirst(21);
    slobj.InsertFirst(11);
    slobj.Display();

    slobj.InsertLast(111);
    slobj.InsertLast(121);
    slobj.Display();

    slobj.InsertAtPos(101, 4);
    slobj.Display();

    slobj.DeleteAtPos(4);
    slobj.Display();

    slobj.DeleteFirst();
    slobj.DeleteFirst();
    slobj.Display();

    slobj.DeleteLast();
    slobj.DeleteLast();
    slobj.Display();

    return 0;
}