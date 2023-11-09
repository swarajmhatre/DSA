#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    // Max heap
    priority_queue<int> maxi;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(2);
    maxi.push(5);
    maxi.push(4);
    maxi.push(3);
    int size = maxi.size();
    for(auto i=0; i < size; i++){
        cout<< maxi.top() << " ";
        maxi.pop();
    }

    // mini.push(1);
    // mini.push(2);
    // mini.push(5);
    // mini.push(4);
    // mini.push(3);
    // int size = mini.size();
    // for(auto i=0; i < size; i++){
    //     cout<< mini.top() << " ";
    //     mini.pop();
    // }

    cout<< "Empty? "<<  mini.empty();
    return 0;
}