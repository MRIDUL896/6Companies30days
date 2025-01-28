//2327. Number of People Aware of a Secret
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    #define mod 1000000007
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int day = i+delay; day<min(n,i+forget) ;day++ ){
                dp[day] = (dp[day] + dp[i])%mod;
            }
        }
        int ans = 0;
        for(int i=0;i<forget;i++) ans = (ans + dp[n-i-1])%mod;
        return ans;
    }
};