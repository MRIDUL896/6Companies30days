//1617. Count Subtrees With Max Distance Between Cities
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int subtree , vector<vector<int>>&dist , int n){
        int cntNodes = 0 , cntEdges = 0 , mxd = 0;
        for(int i = 0 ; i<n; i++){
            if(((subtree>>i)&1) == 0)continue; 
            cntNodes++;
            for(int j = i+1; j<n; j++){
                if(((subtree>>j)&1) == 0)continue;
                if(dist[i][j] == 1) cntEdges++;
                mxd = max(mxd,dist[i][j]);
            }
        }
        if(cntNodes == cntEdges + 1) return mxd;
        return -1;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int>subtrees(n-1,0); // number of subtrees for each distance 
        vector<vector<int>>dist(15 , vector<int>(15,INT_MAX));
        for(auto temp : edges){
            dist[temp[0]-1][temp[1]-1] = 1;
            dist[temp[1]-1][temp[0]-1] = 1;
        }
        for(int k = 0 ; k<n; k++){
            for(int i = 0 ; i<n; i++){
                for(int j = 0 ; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[j][k] == INT_MAX)continue;
                    
                    dist[i][j] = dist[j][i] = min({dist[i][j],dist[j][i],dist[i][k] + dist[k][j]});
                }
            }
        }
        // we iterate over all the subsets
        for(int i = 0 ; i<(1<<n); i++){
            int ans = solve(i,dist,n);
            if(ans > 0){
                subtrees[ans-1]++;
            }
        }
        return subtrees;
    }
};