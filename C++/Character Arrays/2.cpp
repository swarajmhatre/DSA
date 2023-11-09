// #include<iostream>
// using namespace std;
// int main()
// {
//     char name[20];
//     cin >> name;
//     cout<< name;
//     return 0;
// }
// // cin knows space tab and enter

// #include<iostream>
// #include<string>
// using namespace std;
// int main()
// {
//     char arr[100];
//     cin.getline(arr, 50);
//     cout << arr;
 
//     return 0;
// }

#include<iostream>
#include <string.h>
// #include <algorithm>
using namespace std;
// int getLength( char name[]){
//     int length =0;
//     int i=0;
//     while (name[i] != '\0')
//     {
//        length++;
//        i++;
//     }
//     return length;
// }

void reverseCharArray( char name[]){ // Array is always pass by reference
    int i=0;
    int n = strlen(name);
    int j = n-1;
    while (i<=j)
    {
        swap(name[i], name[j]);
        i++;
        j--;

    }

}
int main()
{
    //Length of String
    char name[100];
    cin.getline(name, 50);
    string str = "Swaraj";
    cout<< name;
    // cout<< "Length is: " << getLength(name)<< endl;
    cout<< "Length is: " << strlen(name)<< endl; // for char array and string
    cout<< "Length is: " << str.length()<< endl; //for string only
    cout<< "Initially: "<< name<< endl;
    reverseCharArray(name);
    cout<< "Then: "<< name;
    return 0;
}

