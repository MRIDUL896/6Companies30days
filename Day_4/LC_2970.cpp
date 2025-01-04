//2970. Count the Number of Incremovable Subarrays I
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> last;
        for(int i=n-1;i>=0;i--){
            if(i==n-1 || nums[i]<nums[i+1]) last.push_back(nums[i]);
            else break;
        }
        reverse(last.begin(),last.end());
        if(last.size() == n) return (long long)n*(n+1)/2;
        long long ans = 1 + last.size();
        for(int i=0;i<n-last.size();i++){
            if(i==0 || nums[i] > nums[i-1]){
                ans += last.end() - upper_bound(last.begin(),last.end(),nums[i]) + 1;
            }
            else break;
        }
        return ans;
    }
};