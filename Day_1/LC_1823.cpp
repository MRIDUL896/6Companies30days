//1823. Find the Winner of the Circular Game
#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // int solve(int n,int k){
    //     if(n==1) return 0;
    //     return (solve(n-1)+k) % n;
    // }
    int findTheWinner(int n, int k) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};