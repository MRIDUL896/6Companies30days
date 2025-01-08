//387. First Unique Character in a String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        vector<int> cnt(26,0);
        for(int i=0;i<n;i++){
            char ch=s[i];
            cnt[ch-'a']++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(cnt[ch-'a']==1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};