#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);

    // cout<< v.at(2)<<endl;
    // cout<< v.front()<<endl;
    // cout<< v.back()<<endl;


    // v.pop_back();
    // cout<< v.front()<<endl;
    // cout<< v.back()<<endl;

    // cout<< "Size before: "<< v.size()<< endl;
    // cout<< "capacity before: "<< v.capacity()<< endl;
    // v.clear();
    // cout<< "Size after: "<< v.size()<< endl;
    // cout<< "capacity after: "<< v.capacity()<< endl;

    vector<int> a(5,1);
    vector<int> last(a);
for(int i:last){
    cout<< i<< endl;
}
    return 0;
}