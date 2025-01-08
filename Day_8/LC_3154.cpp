//3154. Find Number of Ways to Reach the K-th Stair
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<long long,int> dp;
    int solve(int i,bool candown,int jump,int k){
        if(i<0||i>k+1) return 0;
        long long key = ((long long)i<<32) | (jump<<1) | candown;
        if(dp.find(key) != dp.end()) return dp[key];
        int ans = 0;
        if(i==k) ans = 1;
        int way1 = 0, way2 = 0;
        if(candown) way1 = solve(i-1,0,jump,k);
        way2 = solve(i+pow(2,jump),1,jump+1,k);
        return dp[key] = way1 + way2 + ans;
    }
    int waysToReachStair(int k) {
        return solve(1,1,0,k);
    }
};