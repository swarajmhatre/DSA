#include<iostream>
using namespace std;
bool ispalindrome(string s){
    int i=0, j= s.length()-1;
    while (i<j)
    {
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str = "aaa";
    int count =0;
    for(int i=0; i< str.length();i++){
        for(int j = i; j< str.length(); j++){
            string temp = str.substr(i, j-i+1);
            if(ispalindrome(temp)){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}