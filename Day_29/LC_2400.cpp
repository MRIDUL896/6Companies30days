//2400. Number of Ways to Reach a Position After Exactly k Steps
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    #define mod 1000000007
    unordered_map<int,unordered_map<int,int>> dp;
    int numberOfWays(int startPos, int endPos, int k) {
        if(startPos == endPos && k==0) return 1;
        if(k == 0||abs(startPos-endPos) > k) return 0;
        if(dp.find(startPos) != dp.end() && dp[startPos].find(k) != dp[startPos].end()) return dp[startPos][k];
        int left = numberOfWays(startPos-1,endPos,k-1)%mod;
        int right = numberOfWays(startPos+1,endPos,k-1)%mod;
        return dp[startPos][k] = (left + right)%mod;
    }
};