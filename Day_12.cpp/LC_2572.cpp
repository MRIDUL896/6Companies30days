//2572. Count the Number of Square-Free Subsets
#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    #define mod 1000000007
    vector<vector<int>> dp;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
    int buildMask(int num){
        if(num == 1) return 0;
        int mask = 0;
        for(int i=0;i<primes.size();i++){
            if(num % primes[i] != 0) continue;
            else if(num % (primes[i]*primes[i]) == 0) return -1;
            else mask = mask | 1<<i;
        }
        return mask;
    }
    int solve(int i,int currMask,vector<int> &masks){
        if(i == masks.size()) return 1;
        if(dp[i][currMask] != -1) return dp[i][currMask];
        int take = 0, notTake = 0;
        if(!(currMask & masks[i])){
            take = solve(i+1,currMask | masks[i],masks)%mod;
        }
        notTake = solve(i+1,currMask,masks)%mod;
        return dp[i][currMask] = (take + notTake)%mod;
    }
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<int>(1024,-1));
        vector<int> masks;
        for(int &num : nums){
            int mask = buildMask(num);
            if(mask != -1) masks.push_back(mask);
        }
        int ans = (solve(0,0,masks)-1)%mod;
        if(ans == -1) return 1000000006;
        return ans;
    }
};