//532. K-diff Pairs in an Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int ans = 0;
        for(pair<int,int> it : mp){
            int num = it.first;
            int freq = it.second;
            if(k == 0) ans += freq > 1 ? 1 : 0;
            else{
                if(mp.find(num + k) != mp.end()) ans++;
            }
        }
        return ans;
    }
};