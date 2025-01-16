//1208. Get Equal Substrings Within Budget
#include<bits/stdc++.h>
using namespace std;\

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int i=0,j=0;
        int ans = 0;
        while(j < n){
            int cost = abs(s[j] - t[j]);
            if(cost <= maxCost){
                maxCost -= cost;
                j++;
            }else{
                if(i < n){
                    maxCost += abs(s[i] - t[i]);
                    i++;
                }else break;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};