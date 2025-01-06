//188. Best Time to Buy and Sell Stock IV
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i,bool isHolding,int n,int k,vector<int>& prices){
        if(i==n || k==0) return 0;
        if(dp[i][k][isHolding] != -1) return dp[i][k][isHolding];
        if(!isHolding){
            int pass = solve(i+1,0,n,k,prices);
            int buy = -prices[i] + solve(i+1,1,n,k,prices);
            return dp[i][k][isHolding] = max(pass,buy);
        }
        int pass = solve(i+1,1,n,k,prices);
        int sell = prices[i] + solve(i+1,0,n,k-1,prices);
        return dp[i][k][isHolding] = max(pass,sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,0,n,k,prices);
    }
};