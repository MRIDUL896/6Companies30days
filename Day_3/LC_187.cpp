//187. Repeated DNA Sequences
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        if(n<=10) return ans;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) mp[s.substr(i,10)]++;
        for(auto [str,freq] : mp){
            cout<<str<<" "<<freq<<endl;
            if(freq > 1) ans.push_back(str);
        }
        return ans;
    }
};