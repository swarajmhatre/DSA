#include<iostream>
#include <algorithm>
#include<string.h>
using namespace std;
bool checkPallindrome(char word[]){
    int i=0;
    int n = strlen(word);
    int j = n-1;
    while (i <j)
    {
        if(word[i] != word[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool isPallindrome(string str){
    int i=0;
    int j = str.length()-1;
    while (i<j)
    {
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str = "noon";
    char arr[100] = "noon";
    // reverse(str.begin(), str.end());
    // cout<< str;
    cout<< isPallindrome(str);
    cout<< checkPallindrome(arr);
    cout<< strupr(arr);
    return 0;
}