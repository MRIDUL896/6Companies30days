//845. Longest Mountain in Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return 0;
        arr.push_back(INT_MAX);
        int ans = 0;
        int i = 0, j = 0;
        while(j<n){
            while(j<n&&arr[j+1]<=arr[j]) j++; 
            i = j;
            while(j<n&&arr[j+1]>arr[j]) j++;
            if(j==n || arr[j+1] == arr[j]){
                i = j;
                continue;
            }
            while(j<n&&arr[j+1]<arr[j]) j++;
            if(j-i+1>=3) ans = max(ans,j-i+1);
            i = j;
        }
        return ans;
    }
};