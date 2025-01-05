//2976. Minimum Cost to Convert String I
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dis(26,vector<long long>(26,1e10));
        for(int i=0;i<26;i++) dis[i][i] = 0;
        for(int i=0;i<original.size();i++){
            if(dis[original[i]-'a'][changed[i]-'a'] > cost[i]){
                dis[original[i]-'a'][changed[i]-'a'] = cost[i];
            }
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<source.length();i++){
            if(dis[source[i]-'a'][target[i]-'a'] == 1e10) return -1;
            ans += dis[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};