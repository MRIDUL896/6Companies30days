//2211. Count Collisions on a Road
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        vector<pair<char,int>> arr;
        for(int i=0;i<n;i++){
            int c = 1;
            while(i+1 < n && directions[i] == directions[i+1]){
                i++,c++;
            }
            arr.push_back({directions[i],c});
        }
        int ans = 0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i].first == 'R' && arr[i+1].first == 'L'){
                ans += arr[i].second + arr[i+1].second;
            }else if(arr[i].first == 'R' && arr[i+1].first == 'S'){
                ans += arr[i].second;
            }else if(arr[i].first == 'S' && arr[i+1].first == 'L'){
                ans += arr[i+1].second;
            }
        }
        return ans;
    }
};