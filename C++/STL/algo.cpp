#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "Binary Search: " << binary_search(v.begin(), v.end(), 5) << endl;
    cout << "lOWER bOUND USING Binary Search: " << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    cout << "lOWER bOUND USING Binary Search: " << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;

    int a = 3;
    int b = 5;

    cout << "Maximum: " << max(a, b) << endl;
    cout << "minimum: " << min(a, b) << endl;

    swap(a, b);
    cout << a << endl;

    string s = "swaraj";
    reverse(s.begin(), s.end());
    cout << "string is: " << s << endl;

    vector<int> vRet(5, 1);
    for (auto i : vRet)
    {
        cout << i << endl;
    }

    cout << endl;
    rotate(v.begin(), v.begin() + 2, v.end());
    for (auto i : v)
    {
        cout << i << endl;
    }

    cout << endl;
    sort(v.begin(), v.end());
    // sort function: quick + heap + insertion sort = intro sort
    for (auto i : v)
    {
        cout << i << endl;
    }
    return 0;
}