#include <bits/stdc++.h>
using namespace std;

vector<int> maxslidingwindow(vector<int>& arr, int k){
    deque<int> dq;
    vector<int> ans;

    for(int i =0;i<arr.size();i++){
        while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        dq.push_back(i);
        if(dq.front() > i-k+1) dq.pop_front();

        if(i>=k-1) ans.push_back(arr[dq.front()]);

    }

    return ans;
}
int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxslidingwindow(arr, k);
    for (int x : res) cout << x << " "; // Output: 3 3 5 5 6 7
}