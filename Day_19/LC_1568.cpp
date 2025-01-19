// 1568. Minimum Number of Days to Disconnect Island
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(i>=m||i<0||j>=n||j<0||vis[i][j]||grid[i][j]==0) return;
        vis[i][j]=1;
        dfs(i+1,j,m,n,grid,vis);
        dfs(i-1,j,m,n,grid,vis);
        dfs(i,j+1,m,n,grid,vis);
        dfs(i,j-1,m,n,grid,vis);
    }
    int numIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    ans++;
                    dfs(i,j,m,n,grid,vis);
                }
            }
        }
        return ans;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int noOfComp = numIslands(grid);
        if(noOfComp==0 || noOfComp>1) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    noOfComp = numIslands(grid);
                    if(noOfComp!=1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};