//1686. Stone Game VI
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> indices(n,0);
        for(int i=0;i<n;i++) indices[i] = i;
        sort(indices.begin(),indices.end(),[&](const int &a,const int &b){
            return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b];
        });
        int alice = 0, bob = 0;
        for(int i=0;i<n;i++){
            if(i&1) bob += bobValues[indices[i]];
            else alice += aliceValues[indices[i]];
        }
        if(alice == bob) return 0;
        return alice > bob ? 1 : -1;
    }
};