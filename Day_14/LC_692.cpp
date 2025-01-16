//692. Top K Frequent Words
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,string> &a, pair<int,string> &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(string str : words) mp[str]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(&cmp)> pq(cmp);
        for(auto it : mp) pq.push({it.second,it.first});
        for(int i=0;i<k;i++){
            if(!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};