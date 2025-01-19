//2223. Sum of Scores of Built Strings
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> Z(n, 0); // Z-array
        int l = 0, r = 0;    // [l, r] is the current Z-box
        long long sum = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                Z[i] = min(r - i + 1, Z[i - l]); // Use previously computed values
            }
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                Z[i]++;
            }
            if (i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
        }
        // Add all Z-values plus the length of the string (for s itself)
        for (int z : Z) {
            cout<<z<<" ";
            sum += z;
        }
        sum += n; // Include the full length of the string
        return sum;
    }
};
