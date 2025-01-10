//994. Rotting oranges
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j] == 2) q.push({i,j});
        int timer = 0;
        while(!q.empty()){
            int num = q.size();
            for(int i=0;i<num;i++){
                pair<int,int> rowcol = q.front();
                q.pop();
                vector<int> dx = {1,0,-1,0};
                vector<int> dy = {0,1,0,-1};
                for(int j=0;j<4;j++){
                    int nrow = rowcol.first + dx[j];
                    int ncol = rowcol.second + dy[j];
                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(!q.empty()) timer++;
        }
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j] == 1) return -1;
        return timer;
    }
};