#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr{1,2,3,4,5};
    int n = arr.size();
    for(int i=0; i< n-1; i++){
        int minIndex = i;
        for(int j = i+1; j< n; j++){
            if(arr[i] < minIndex){
                minIndex =j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    for(int i=0; i<n; i++){
        cout<< arr[i]<< endl;
    }
    return 0;
}


// TC = O(n2)
// SC = O(n)
// Stable