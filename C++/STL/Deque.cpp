#include<iostream>
#include <deque>
using namespace std;
int main()
{
    deque <int> d;
    d.push_back(1);
    d.push_front(2);
    for(int i:d){
        cout<<i<<endl;
    }
    // d.pop_front();

    cout<<"print first index element "<< d.at(1)<<endl;;

    cout<<"front: "<<d.front()<<endl;
    cout<<"back: "<<d.back()<<endl;
    cout<<d.size()<< endl;

    d.erase(d.begin(), d.end()-1);
    cout<<d.size()<< endl;
    cout<<d.at(0)<< endl;

    return 0;
}