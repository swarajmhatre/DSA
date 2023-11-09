#include<iostream>
#include <vector>
using namespace std;
int main()
{   
    vector<int> arr{10,1,7,6,14,9};
    int n = arr.size();
    for(int round = 1; round < n; round++){
        // Step A: Fetch
        int val = arr[round];

        // step 2: Compare
         int j = round -1;
        for(; j >= 0; j--){
           
            if( val < arr[j]){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = val;
    }
    for( int i=0; i< n; i++){
        cout<< arr[i]<< endl;
    }
    return 0;
}

// T.C. = O(n^2)
// S.C. = O(1);
// Best case T.C. = O(n) When Array is already sorted
// It is stable