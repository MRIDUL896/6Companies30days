// 462. Minimum Moves to Equal Array Elements II
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cost = 0, i = 0, j = n-1;
        while(i<j){
            cost += nums[j--] - nums[i++];
        }   
        return cost;
    }
};