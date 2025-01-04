// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,(int)1e8));
        for(int i=0;i<edges.size();i++){
            dis[edges[i][0]][edges[i][1]] = edges[i][2];
            dis[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++) dis[i][i] = 0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k] + dis[k][j] < dis[i][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    } 
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int city ,no = INT_MAX;
        for(int i=0;i<n;i++){
            int reaching = 0;
            for(int j=0;j<n;j++){
                if(dis[i][j] <= distanceThreshold){
                    reaching++;
                }
            }
            if(reaching <= no){
                city = i;
                no = reaching;
            }
        }
        return city;
    }
};