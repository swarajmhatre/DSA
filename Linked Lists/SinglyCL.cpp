#include <iostream>
using namespace std;

typedef class Node
{
public:
    int data;
    struct Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int iValue)
    {
        data = iValue;
        next = NULL;
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

        cout << "Elements of the Linked List are: ";
        for (int i = 1; i <= iSize; i++)
        {
            cout << "|" << temp->data << "|-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int Count()
    {
        return iSize;
    }
};

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
};

SinglyCL::SinglyCL()
{
    Last = NULL;
}

SinglyCL:: ~SinglyCL(){
    PNODE temp = First;
    for(int i=0; i<= iSize; i++){
        temp = First;
        First = First->next;
        delete temp;
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

void SinglyCL :: InsertLast(int iNo){
    PNODE newn = new NODE(iNo);
    if((First == NULL) && (Last == NULL)){
        First = newn;
        Last = newn;
    }
    else{
        newn->next = First;
        Last->next = newn;
        Last = newn;
    }
    iSize++;
}

void SinglyCL :: InsertAtPos(int iNo, int iPos){
    if((iPos < 1)|| (iPos> iSize+1)){
        cout<< "Invalid Input\n";
        return;
    }

    if(iPos == 1){
        InsertFirst(iNo);
    }
    else if(iPos == iSize+1){
        InsertLast(iNo);
    }
    else{
        PNODE newn = new NODE(iNo);
        PNODE temp = First;
        for(int i; i< (iPos-1); i++){
            temp= temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iSize++;
}

void SinglyCL:: DeleteFirst(){
    if((First == NULL) && (Last == NULL)){
        cout<< "Nothing to Delete...\n";
        return;
    }
    else if(First == Last){
        delete First;
        First = NULL;
        Last = NULL;
    }
    else{
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iSize--;
}

void SinglyCL:: DeleteLast(){
    if((First == NULL) && (Last == NULL)){
        cout<<"Nothing to Delete...\n";
        return;
    }
    else if(First == Last){
        delete First;
        First = NULL;
        Last = NULL;
    }
    else{
        PNODE temp = First;
        for(int i =1; i< iSize-1; i++){
            temp = temp->next;
        }
        temp->next = First;
        delete Last;
        Last = temp;
    }
    iSize--;
}

void SinglyCL :: DeleteAtPos(int iPos){
    if((iPos < 1) || (iPos > iSize)){
        cout << "Invalid Input";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iSize){
        DeleteLast();
    }
    else{
        PNODE temp = First;
        PNODE tempX = NULL;
        for(int i=1; i< iPos-1; i++){
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;
    }
}

int main()
{
    SinglyCL obj;
    
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
