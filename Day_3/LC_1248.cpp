//1248. Count Number of Nice Subarrays
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bull = 0, cow = 0;
        vector<int> secretCount(10, 0), guessCount(10, 0);
        for(int i=0;i<n;i++) {
            if(secret[i] == guess[i]) bull++;
            else{
                secretCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++) cow += min(secretCount[i], guessCount[i]);
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};