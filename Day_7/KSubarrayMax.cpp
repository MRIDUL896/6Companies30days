//K Sized Subarray Maximum
#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1) ans.push_back(arr[dq.front()]);
    }
    return ans;
}