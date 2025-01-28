//1765. Map of Highest Peak
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    for(int k=0;k<4;k++){
                        int i_ = i + dx[k];
                        int j_ = j + dy[k];
                        if(i_>=0 && i_<m && j_>=0 && j_<n && !isWater[i_][j_] && !vis[i_][j_]){
                            q.push({i_,j_});
                            vis[i_][j_] = 1;
                        }
                    }
                }
            }
        }
        int t = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();
                ans[r][c] = t;
                for(int k=0;k<4;k++){
                    int i_ = r + dx[k];
                    int j_ = c + dy[k];
                    if(i_>=0 && i_<m && j_>=0 && j_<n && !isWater[i_][j_] && !vis[i_][j_]){
                        q.push({i_,j_});
                        vis[i_][j_] = 1;
                    }
                }
            }
            t++;
        }
        return ans;
    }
};