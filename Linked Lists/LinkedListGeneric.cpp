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

template <class T>
class NodeG
{
public:
    T data;
    NodeG *next;
    NodeG *prev;

    NodeG()
    {
        next = NULL;
        prev = NULL;
    }

    NodeG(T data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//_______________________________________________________________________Linked List____________________________________________________________________
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class LinkedList
{
protected:
    NodeG<T> *First;
    int iSize;

public:
    LinkedList()
    {
        First = NULL;
        iSize = 0;
    }
    virtual void InsertFirst(T iNo) = 0;
    virtual void InsertLast(T iNo) = 0;
    virtual void InsertAtPos(T iNo, int iPos) = 0;
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
template <class T>
class DoublyCL : public LinkedList<T>
{
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;
    NodeG<T> *Last;

public:
    DoublyCL();
    ~DoublyCL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    Last = NULL;
}

template <class T>
DoublyCL<T>::~DoublyCL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeG<T> *temp = First;
    cout << "\nThe elements of the Linked List Are: ";
    cout << "<=> ";
    for (int i = 1; i <= iSize; i++)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
}

template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
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

template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
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

template <class T>
void DoublyCL<T>::InsertAtPos(T iNo, int iPos)
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
        NodeG<T> *newn = new NodeG<T>(iNo);
        NodeG<T> *temp = First;
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

template <class T>
void DoublyCL<T>::DeleteFirst()
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

template <class T>
void DoublyCL<T>::DeleteLast()
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

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
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
        NodeG<T> *temp = First;
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
template <class T>
class DoublyLL : public LinkedList<T>
{
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;

public:
    ~DoublyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
DoublyLL<T>::~DoublyLL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    NodeG<T> *temp = First;
    cout << "\nThe elements of the Linked List Are: ";
    cout << "NULL <=> ";
    for (int i = 1; i <= iSize; i++)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL ";
}

template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
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

template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize; i++)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iSize++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
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
        NodeG<T> *newn = new NodeG<T>(iNo);
        NodeG<T> *temp = First;
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

template <class T>
void DoublyLL<T>::DeleteFirst()
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

template <class T>
void DoublyLL<T>::DeleteLast()
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
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
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
        NodeG<T> *temp = First;
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
template <class T>
class SinglyCL : public LinkedList<T>
{
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;
    NodeG<T> *Last;

public:
    SinglyCL();
    ~SinglyCL();

    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    Last = NULL;
}

template <class T>
SinglyCL<T>::~SinglyCL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeG<T> *temp = First;
    printf("\nThe Linked list is: ");
    for (int i = 1; i <= iSize; i++)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
}

template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

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

template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);
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

template <class T>
void SinglyCL<T>::InsertAtPos(T iNo, int iPos)
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
        NodeG<T> *newn = new NodeG<T>(iNo);
        NodeG<T> *temp = First;
        for (int i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
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

template <class T>
void SinglyCL<T>::DeleteLast()
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
        NodeG<T> *temp = First;
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

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
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
        NodeG<T> *temp = First;
        NodeG<T> *tempX = NULL;
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
template <class T>
class SinglyLL : public LinkedList<T>
{
private:
    using LinkedList<T>::First;
    using LinkedList<T>::iSize;

public:
    ~SinglyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
};

template <class T>
SinglyLL<T>::~SinglyLL()
{
    NodeG<T> *temp = First;
    for (int i = 0; i <= iSize; i++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

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

template <class T>
void SinglyLL<T>::InsertLast(T iNo)
{
    NodeG<T> *newn = new NodeG<T>(iNo);

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
        NodeG<T> *temp = First;
        for (int i = 1; i < iSize; i++)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T iNo, int iPos)
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
        NodeG<T> *temp = First;
        NodeG<T> *newn = new NodeG<T>(iNo);

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iSize++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
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
        NodeG<T> *temp = First;
        First = First->next;
        delete temp;
    }
    iSize--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
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
        NodeG<T> *temp = First;
        for (int i = 0; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
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
        NodeG<T> *temp = First;
        NodeG<T> *tempX = NULL;

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

template <class T>
void SinglyLL<T>::Display()
{
    NodeG<T> *temp = First;
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
    DoublyCL<int> dcobj;
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

    DoublyLL<int> dlobj;
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

    SinglyCL<int> scobj;
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

    SinglyLL<int> slobj;
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