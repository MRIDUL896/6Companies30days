//451. Sort Characters By Frequency
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]++;
        priority_queue<pair<int,char>> pq;
        for(auto i : mp) pq.push({i.second,i.first});
        string ans="";
        while(!pq.empty()){
            pair<int,char> curr=pq.top();
            int cnt=curr.first;
            char ch=curr.second;
            for(int i=0;i<cnt;i++) ans.push_back(ch);
            pq.pop();
        }
        return ans;
    }
};