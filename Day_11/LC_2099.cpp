//2099. Find Subsequence of Length K With the Largest Sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        vector<pair<int,int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int> res;
        for(auto num : ans) res.push_back(num.first);
        return res;
    }
};