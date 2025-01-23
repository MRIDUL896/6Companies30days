//2343. Query Kth Smallest Trimmed Number
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        int l = nums[0].length();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int k = queries[i][0];
            int trim = queries[i][1];
            vector<pair<string,int>> pq;
            for(int j=0;j<m;j++) pq.push_back({nums[j].substr(l-trim,trim),j});
            sort(pq.begin(),pq.end());
            ans.push_back(pq[k-1].second);
        }
        return ans;
    }
};