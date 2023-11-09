#include <iostream>
#include<array>
using namespace std;
int main()
{
    array<int,4> a = {1,2,3,4};
    int size = a.size();
    for(int i=0; i<size; i++){
        cout<< a.at(i) <<endl;
    }
    cout<<"Chalo"<<endl;
cout<< a.empty()<<endl;
cout<<"First: "<< a.front()<<endl;
cout<<"Last: " <<a.back()<<endl;
    
    return 0;
}