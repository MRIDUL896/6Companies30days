//MCM print
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<string,int>>> dp;
    pair<string,int> solve(int i,int j,vector<int> &arr){
        if(i==j){
            string st = "";
            st += 'A' + j -1;
            return {st,0};
        } 
        if(dp[i][j].second != -1) return dp[i][j];
        int mini = 1e10;
        string str = "";
        for(int k=i;k<j;k++){
            auto left = solve(i,k,arr);
            auto right = solve(k+1,j,arr);
            int curr = left.second + right.second + arr[i-1]*arr[k]*arr[j];
            if(curr < mini){
                mini = curr;
                str = "(" + left.first + right.first + ")";
            }
        }
        
        return dp[i][j] = {str,mini};
    }
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        dp.resize(n,vector<pair<string,int>>(n,{"",-1}));
        // cout<<solve(1,n-1,arr).first;
        return solve(1,n-1,arr).first;
    }