#include <bits/stdc++.h>
using namespace std;

vector<double> averageOfSubarrays(vector<int>& arr, int k) {
    vector<double> ans;
    int windowSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        windowSum += arr[i];

        if (i >= k-1) {
            ans.push_back((double)windowSum / k);
            windowSum -= arr[i-k+1];
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int k = 2;
    vector<double> res = averageOfSubarrays(arr, k);
    for (double x : res) cout << x << " "; // Output: 1.5 2.5 3.5 4.5
}
