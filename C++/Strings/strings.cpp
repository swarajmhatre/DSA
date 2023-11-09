#include<iostream>
using namespace std;
bool strcmpX(string a, string b){
    if( a.length() != b.length()){
        return false;
    }
    else{
        int i=0;
        for( i=0; i < a.length(); i++){
            if(a[i] != b[i]){
                return false;
            }
        }
    }
    return true;
}
int main()
{
    // string str = "Swaraj Mhatre";
    // getline(cin, str);
    // str[2] = '\0';
    // cout<< str <<endl; 
    // cout<< str.size() << endl; 
    // cout<< str.length() << endl; 
    // cout<< str.empty() << endl; 

    // str.push_back('X');
    // cout << str <<endl;
    // str.pop_back();

    // cout << str <<endl;
    // cout << str.substr(0,6) <<endl; //INP HAI

    // string a = "Love";
    // string b = "Lover";
    // if(strcmpX(a, b)){
    //     cout << "a & b are exactly same strings" << a.compare(b);
    // }
    // else{
    //     cout << " a & b are not same";
    // }

    // string x = "abcd";
    // string y ="bcda";
    // // cout << x.compare(y)<< endl;
    // // cout << x.find('d')<< endl;

    // string sentence = "Hello G Kaise ho saare";
    // cout<< sentence.find("asdflkj")<< endl;
    // if(sentence.find("asdfasdf") == std::string:: npos){
    //     cout<< "Not foun\n";
    // }

    string str = "This is my first message";
    string word = "Babbar";
    str.replace(0, 4, word);
    str.replace(13, 5, "Second");
    cout << str << endl;

    str.erase(13,7);
    cout<< str << endl;
    return 0;
}