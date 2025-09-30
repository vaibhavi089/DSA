#include <bits/stdc++.h>
using namespace std;

vector<int> firstnegativewindow(vector<int>& arr, int k){
    deque<int> dq;
    vector<int> ans;

    for(int i = 0;i<arr.size();i++){
        if(arr[i]<0) dq.push_back(i);

        if(!dq.empty() && dq.front() > i-k+1) dq.pop_front();

        if(i>=k-1){
            ans.push_back(dq.empty() ? 0 : arr[dq.front()]);


        }
    }
    return ans;
}
int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> res = firstnegativewindow(arr, k);
    for (int x : res) cout << x << " "; // Output: -1 -1 -7 -15 -15 0
}