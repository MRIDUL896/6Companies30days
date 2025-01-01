//354. Russian Doll Envelopes
#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int upper_bound(vector<int> &curr,vector<vector<int>>& dp){
        int s = 0, e = dp.size()-1;
        int ub = dp.size();
        while(s<=e){
            int m = s + (e-s)/2;
            if(curr[1]<=dp[m][1]){
                ub = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ub;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            vector<int> curr = envelopes[i];
            int ub = upper_bound(curr,dp);
            if(ub == dp.size()){
                dp.push_back(curr);
            }else{
                dp[ub] = curr;
            }
        }
        return dp.size();
    }
};