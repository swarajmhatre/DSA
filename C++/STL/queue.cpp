#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue <string> q;
    q.push("Swaraj");
    q.push("Nitin");
    q.push("Mhatre");

    cout<<"First element: " << q.front()<<endl;
    cout<<"size: "<<q.size()<<endl;

    q.pop();

    cout<<"First element: " << q.front()<<endl;
    cout<<"size: "<<q.size();
    return 0;
}