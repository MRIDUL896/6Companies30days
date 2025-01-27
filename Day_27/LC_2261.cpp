//2261. K Divisible Elements Subarrays
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();  
        unordered_set<string> set;
        for(int i=0;i<n;i++){
            int count = 0;
            string str = "";
            for(int j=i;j<n;j++){
                if(nums[j]%p == 0) count++;
                if(count > k) break;
                str += to_string(nums[j]) + "#";
                set.insert(str);
            }
        }
        return set.size();
    }
};