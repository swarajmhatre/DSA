#include<iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map <char, int> mp;
    mp['a'] =0;
    mp['a']++;
    mp['a']++;
    mp['a']++;
    mp['a']++;
    mp['a']++;
    while (mp['a']>0)
    {
        cout<< mp['a']<<" ";
        mp['a']--;
    }
    
    return 0;
}