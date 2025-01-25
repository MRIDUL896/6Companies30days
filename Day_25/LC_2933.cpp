//2933. High-Access Employees
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    bool within(string &a,string &b){
        int t1 = stoi(a);
        int t2 = stoi(b);
        int hours = t2/100 - t1/100;
        int mins = t2%100 - t1%100;
        int diff = hours*60 + mins;
        return diff < 60;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n = access_times.size();
        sort(access_times.begin(),access_times.end());
        vector<string> ans;
        int i = 0, j = 0;
        while(j<n){
            while(j<n && access_times[i][0] == access_times[j][0] && within(access_times[i][1],access_times[j][1])){
                if(j-i+1 >= 3){
                    ans.push_back(access_times[i][0]);
                    while(j<n && access_times[i][0] == access_times[j][0]) j++;
                }else j++;
            }
            i++;
        }
        return ans;
    }
};