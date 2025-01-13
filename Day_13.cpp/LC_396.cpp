//396. Rotate Function
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int arrSum = accumulate(nums.begin(),nums.end(),0);
        int currAns = 0;
        for(int i=0;i<n;i++) currAns += i*nums[i];
        ans = max(ans,currAns);
        for(int i=1;i<n;i++){
            int nextAns = currAns + arrSum - (n)*nums[n-i];
            currAns = nextAns;
            ans = max(ans,currAns);
        }
        return ans;
    }
};