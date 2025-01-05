//638. Shopping Offers
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int need, int n, vector<int>& price, vector<vector<int>>& special, unordered_map<int, int>& memo) {
        if (need == 0) return 0; 
        if (memo.find(need) != memo.end()) return memo[need];
        int regular = 0;
        for (int i = 0; i < n; i++) {
            int needItemFreq = (need >> (i * 4)) & 15; 
            regular += needItemFreq * price[i];
        }
        int minCost = regular;
        for (auto& offer : special) {
            int newNeed = need;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                int needItemFreq = (newNeed >> (i * 4)) & 15;  
                if (needItemFreq < offer[i]) {  
                    valid = false;
                    break;
                }
                newNeed -= (offer[i] << (i * 4));  
            }
            if (!valid) continue;
            int offerCost = offer.back() + solve(newNeed, n, price, special, memo);
            minCost = min(minCost, offerCost);
        }
        return memo[need] = minCost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();
        int need = 0;
        for (int i = 0; i < n; i++) {
            need |= (needs[i] << (i * 4));
        }
        unordered_map<int, int> memo;
        return solve(need, n, price, special, memo);
    }
};
