/*Missing And Repeating
Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b.
Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n]*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        int MXR = 0 , rep;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(mp[arr[i]] == 2) rep = arr[i];
            MXR ^= arr[i];
            MXR ^= i+1;
        }
        return {rep,rep^MXR};
    }
    
};