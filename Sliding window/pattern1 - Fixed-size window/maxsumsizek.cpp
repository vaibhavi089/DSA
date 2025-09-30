#include <bits/stdc++.h>
using namespace std;

int maxsumsubarray(vector<int>& arr,int k){
    int n = arr.size();
    int windowsum  = 0;
    int maxsum = INT_MIN;

    for(int i = 0;i<k;i++){
        windowsum += arr[i];
    }

    maxsum = windowsum;
    for(int i = k;i<n;i++){
        windowsum += arr[i] - arr[i-k];
        maxsum = max(maxsum,windowsum);
        
    }
    return maxsum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << maxsumsubarray(arr, k) << endl; // Output: 9 (5+1+3)
}