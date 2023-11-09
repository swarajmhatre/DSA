#include<iostream>
#include <string.h>
using namespace std;
void struprt(char arr[]){
    int n = strlen(arr);
    for( int i=0; i< n ; i++){
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            arr[i] = arr[i] - 32;
        }
    }
}
void strlwrt(char arr[]){
    int n = strlen(arr);
    for( int i=0; i< n ; i++){
        if(arr[i] >= 'A' && arr[i] <= 'Z'){
            arr[i] = arr[i] + 32;
        }
    }
}
int main()
{
    string str = "swaraj";
    str[2] = 'c';
    str.replace(0,2, "st");
    cout << str;
    char arr[100] = "SwAraj";
    struprt(arr);
    cout << arr;
    strlwrt(arr);
    cout << arr;
    return 0;
}