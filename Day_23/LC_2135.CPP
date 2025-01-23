//2135. Count Words Obtained After Adding a Letter
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> set;
        for(int i=0;i<startWords.size();i++){
            string str = startWords[i];
            int mask = 0;
            for(int j=0;j<str.size();j++) mask |= (1<<(str[j] - 'a'));
            set.insert(mask);
        }
        int ans = 0;
        for(int i=0;i<targetWords.size();i++){
            string str = targetWords[i];
            int targetMask = 0;
            for(int j=0;j<str.size();j++) targetMask |= (1<<(str[j] - 'a'));
            for(int j=0;j<str.size();j++){
                int mask = targetMask & ~(1<<(str[j] - 'a'));
                if(set.find(mask) != set.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};