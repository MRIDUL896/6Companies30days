//2707. Extra Characters in a String
#include<bits/stdc++.h>
using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
    unordered_set<string> st(dictionary.begin(),dictionary.end());
    vector<int> dp(s.length()+1,0);
    for(int i=s.length()-1;i>=0;i--){
        int ans = 1 + dp[i+1];
        for(int j=s.length()-1;j>=i;j--){
            string substr = s.substr(i,j-i+1);
            if(st.find(substr) != st.end()){
                ans = min(ans,dp[j+1]);
            }
        }
        dp[i] = ans;
    }
    return dp[0];
}