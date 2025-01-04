//2002. Maximum Product of the Length of Two Palindromic Subsequences
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalin(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int solve(int i,string &s1,string &s2,string &s){
        if(i==s.length()){
            if(isPalin(s1) && isPalin(s2)){
                return s1.length()*s2.length();
            }else return 0;
        }
        int notTake = solve(i+1,s1,s2,s);
        s1.push_back(s[i]);
        int take1 = solve(i+1,s1,s2,s);
        s1.pop_back();
        s2.push_back(s[i]);
        int take2 = solve(i+1,s1,s2,s);
        s2.pop_back();
        return max(notTake,max(take1,take2));
    }
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        return solve(0,s1,s2,s);;
    }
};