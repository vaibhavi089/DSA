// key learning - if we have to keep count use hashmap and if we wannna know distinct elements we can simply use length of hashmap 
#include <bits/stdc++.h>
using namespace std;

void countDistinct(int arr[], int n, int k){
    unordered_map<int,int> freq;
    vector<int> result;

    for(int i=0;i<k;i++){
        freq[arr[i]]++;
    }
    result.push_back(freq.size());

    for(int i =k;i<n;i++){
        freq[arr[i-k]]--;
        if(freq[arr[i-k]] == 0){
            freq.erase(arr[i-k]); // we are using number itself thats why i-k and why to keep number if their freq got zero so juts remove them.
        }
        freq[arr[i]]++;
    }

    for(int x : result) cout << x << " ";
}

int main() {
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    countDistinct(arr, n, k);
    return 0;
}