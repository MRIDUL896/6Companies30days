//216. Combination Sum III
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public: 
    vector<vector<int>> ans;
    void solve(int i,int k,int n,vector<int> &temp){
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(i==10 || n<=0 || k<=0) return;
        solve(i+1,k,n,temp);
        temp.push_back(i);
        solve(i+1,k-1,n-i,temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>=n) return {};
        vector<int> temp;
        solve(1,k,n,temp);
        return ans;
    }
};