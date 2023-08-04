#include <iostream>
using namespace std;

typedef class Node
{
    int data;
    struct Node * next;

    Node(){
        data =0;
        next = NULL;
    }

    Node(int iValue){
        data = iValue;
        next = NULL;
    }

}NODE, *PNODE;

class LinkedList{
    private:
    PNODE First;
    PNODE Last;
    int iSize;

    public:

}

