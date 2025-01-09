//168. Excel Sheet Column Title
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber){
            char ch = (columnNumber-1)%26 + 'A';
            ans += ch;
            columnNumber--;
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};