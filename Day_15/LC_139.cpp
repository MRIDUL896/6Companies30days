//139. Word Break
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> set;
    vector<vector<int>> dp;
    bool solve(int i,int j,string s){
        if(i>j) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(set.find(s.substr(i,j-i+1)) != set.end()) return true;
        for(int k=i;k<j;k++){
            bool ans1 = solve(i,k,s);
            bool ans2 = solve(k+1,j,s);
            if(ans1 && ans2) return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set.insert(wordDict.begin(),wordDict.end());
        int n = s.length();
        dp.resize(n,vector<int>(n,-1));
        return solve(0,s.length()-1,s);
    }
};