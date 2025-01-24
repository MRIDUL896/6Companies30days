//1385. Find the Distance Value Between Two Arrays
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr,int target){
        int n = arr.size();
        int s = 0 , e = n-1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(arr[m] >= target) e = m-1;
            else s = m + 1;
        }
        return s;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(int i=0;i<arr1.size();i++){ 
            int critIdx = lowerBound(arr2,arr1[i]);
            if(critIdx < arr2.size() && abs(arr1[i] - arr2[critIdx]) <= d) continue;
            if(critIdx-1 >= 0 && abs(arr1[i] - arr2[critIdx-1]) <=d) continue;
            ans++;
        }
        return ans;
    }
};