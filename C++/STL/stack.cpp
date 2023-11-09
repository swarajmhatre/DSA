#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<string> s;

    s.push("swaraj");
    s.push("nitin");
    s.push("mhatre");
    cout<<"top element: "<< s.top()<<endl;

    s.pop();
    cout<<"top element: "<< s.top()<<endl;

    cout<< "size of stack: "<< s.size()<< endl;
    cout<< "isempty?: "<< s.empty()<< endl;
    return 0;
}