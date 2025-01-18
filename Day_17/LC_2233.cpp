//2233. Maximum Product After K Increments
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    # define mod 1000000007 
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++) pq.push(nums[i]);
        for(int i=0;i<k;i++){
            int ele = pq.top();
            pq.pop();
            ele++;
            pq.push(ele);
        }
        long long prod = 1;
        while(!pq.empty()){
            prod = (prod*pq.top())%mod;
            pq.pop();
        }
        return prod;
    }
};