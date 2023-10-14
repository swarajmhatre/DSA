#include <iostream>
using namespace std;

// Node class to represent individual elements in the linked lists
class Node {
public:
    int data;
    Node *next;
    Node *prev;

    // Constructors
    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int iNo) {
        data = iNo;
        next = nullptr;
        prev = nullptr;
    }
};

// Define aliases for Node and PNODE for readability
typedef class Node NODE, *PNODE;

// Base class for the linked list
class LinkedList {
protected:
    PNODE First;
    int iSize;

public:
    LinkedList() {
        First = nullptr;
        iSize = 0;
    }

    // Pure virtual functions for inserting and deleting elements
    virtual void InsertFirst(int iNo) = 0;
    virtual void InsertLast(int iNo) = 0;
    virtual void InsertAtPos(int iNo, int iPos) = 0;
    virtual void DeleteFirst() = 0;
    virtual void DeleteLast() = 0;
    virtual void DeleteAtPos(int iPos) = 0;

    int Count() {
        return iSize;
    }
};

// Doubly Circular Linked List class
class DoublyCL : public LinkedList {
private:
    PNODE Last;

public:
    DoublyCL() {
        Last = nullptr;
    }

    ~DoublyCL() {
        PNODE temp = First;
        for (int i = 0; i <= iSize; i++) {
            temp = First;
            First = First->next;
            delete temp;
        }
    }

    // Insert element at the beginning of the list
    void InsertFirst(int iNo) {
        PNODE newn = new Node(iNo);
        if (First == nullptr && Last == nullptr) {
            First = newn;
            Last = newn;
        } else {
            newn->next = First;
            First->prev = newn;
            First = newn;
        }
        Last->next = First;
        First->prev = Last;
        iSize++;
    }

    // Insert element at the end of the list
    void InsertLast(int iNo) {
        PNODE newn = new NODE(iNo);
        if (First == nullptr && Last == nullptr) {
            First = newn;
            Last = newn;
        } else {
            Last->next = newn;
            newn->prev = Last;
            Last = newn;
        }
        Last->next = First;
        First->prev = Last;
        iSize++;
    }

    // Insert element at a specific position
    void InsertAtPos(int iNo, int iPos) {
        if (iPos < 1 || iPos > iSize + 1) {
            cout << "\nInvalid Input!";
            return;
        }
        if (iPos == 1) {
            InsertFirst(iNo);
        } else if (iPos == iSize + 1) {
            InsertLast(iNo);
        } else {
            PNODE newn = new NODE(iNo);
            PNODE temp = First;
            for (int i = 1; i < iPos - 1; i++) {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            newn->prev = temp;
            newn->next->prev = newn;
            iSize++;
        }
    }

    // Delete the first element
    void DeleteFirst() {
        if (First == nullptr && Last == nullptr) {
            cout << "\nNothing to delete!";
            return;
        }
        if (First == Last) {
            delete First;
            First = nullptr;
            Last = nullptr;
        } else {
            First = First->next;
            delete First->prev;
            First->prev = Last;
            Last->next = First;
        }
        iSize--;
    }

    // Delete the last element
    void DeleteLast() {
        if (First == nullptr && Last == nullptr) {
            cout << "\nInvalid Input!";
            return;
        }
        if (First == Last) {
            delete Last;
            First = nullptr;
            Last = nullptr;
        } else {
            Last = Last->prev;
            delete Last->next;
            Last->next = First;
            First->prev = Last;
        }
        iSize--;
    }

    // Delete an element at a specific position
    void DeleteAtPos(int iPos) {
        if (iPos < 1 || iPos > iSize) {
            cout << "\nInvalid Input!";
            return;
        }
        if (iPos == 1) {
            DeleteFirst();
        } else if (iPos == iSize + 1) {
            DeleteLast();
        } else {
            PNODE temp = First;
            for (int i = 1; i < iPos - 1; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
            iSize--;
        }
    }

    // Display the elements of the linked list
    void Display() {
        PNODE temp = First;
        cout << "\nThe elements of the Linked List Are: ";
        cout << "<=> ";
        for (int i = 1; i <= iSize; i++) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
    }
};

// Doubly Linear Linked List class (similar to DoublyCL, just no circular structure)
class DoublyLL : public LinkedList {
public:
    ~DoublyLL() {
        PNODE temp = First;
        for (int i = 0; i <= iSize; i++) {
            temp = First;
            First = First->next;
            delete temp;
        }
    }

    // ... InsertFirst, InsertLast, InsertAtPos, DeleteFirst, DeleteLast, DeleteAtPos functions are similar to DoublyCL

    void Display() {
        PNODE temp = First;
        cout << "\nThe elements of the Linked List Are: ";
        cout << "NULL <=> ";
        for (int i = 1; i <= iSize; i++) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL ";
    }
};

// Singly Circular Linked List class (similar to DoublyCL, but no previous pointers)
class SinglyCL : public LinkedList {
private:
    PNODE Last;

public:
    SinglyCL() {
        Last = nullptr;
    }

    ~SinglyCL() {
        PNODE temp = First;
        for (int i = 0; i <= iSize; i++) {
            temp = First;
            First = First->next;
            delete temp;
        }
    }

    // ... InsertFirst, InsertLast, InsertAtPos, DeleteFirst, DeleteLast, DeleteAtPos functions are similar to DoublyCL

    void Display() {
        PNODE temp = First;
        printf("\nThe Linked list is: ");
        for (int i = 1; i <= iSize; i++) {
            printf("|%d|->", temp->data);
            temp = temp->next;
        }
    }
};

// Singly Linear Linked List class (similar to SinglyCL, but not circular)
class SinglyLL : public LinkedList {
public:
    ~SinglyLL() {
        PNODE temp = First;
        for (int i = 0; i <= iSize; i++) {
            temp = First;
            First = First->next;
            delete temp;
        }
    }

    // ... InsertFirst, InsertLast, InsertAtPos, DeleteFirst, DeleteLast, DeleteAtPos functions are similar to SinglyCL

    void Display() {
        PNODE temp = First;
        printf("The Linked list is: ");
        for (int i = 1; i <= iSize; i++) {
            printf("|%d|->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
// Continue the main function for other linked list types
int main() {
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

    cout << endl << endl;

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

    cout << endl << endl;

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

    cout << endl << endl;

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
