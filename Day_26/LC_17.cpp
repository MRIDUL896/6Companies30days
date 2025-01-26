//17. Letter Combinations of a Phone Number
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int index,string temp,string digits){
        if(index == digits.size()){
            if(!temp.empty()) ans.push_back(temp);
            return;
        }
        for(char ch : mp[digits[index] - '0']){
            temp += ch;
            solve(index+1,temp,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        solve(0,temp,digits);
        return ans;
    }
};