#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> m;

    m[1] = "babbar";
    m[13] = "kumar";
    m[2] = "love";
    m.insert({5, "bheem"});

    cout << "Before Erase: \n";
    for (auto i : m)
    {
        cout << i.second << ", ";
    }
    cout << endl;
    cout << "finding 13: " << m.count(13);
    cout << endl;
    m.erase(13);
    cout << "After Erase: \n";
    for (auto i : m)
    {
        cout << i.second << ", ";
    }
    cout << endl;
    cout << "finding 13: " << m.count(13)<<endl;

    auto it = m.find(1);
    for(auto i= it; i != m.end(); i++){
        cout<< (*i).first<<endl;
    }
    return 0;
}