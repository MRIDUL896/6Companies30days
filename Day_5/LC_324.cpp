// 324. Wiggle Sort II
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        int i=1,j=n-1;
        while(i<n){
            ans[i] = nums[j];
            j--,i+=2;
        }
        i = 0;
        while(i<n && j>=0){
            ans[i] = nums[j];
            j--,i+=2;
        }
        nums = ans;
    }
};