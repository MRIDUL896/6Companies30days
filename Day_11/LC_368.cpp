//368. Largest Divisible Subset
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int maxSize = 0, maxIndex = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }
        vector<int> result;
        while(maxIndex != -1){
            result.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }
        return result;
    }
};
