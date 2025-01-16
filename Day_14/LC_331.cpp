//331. Verify Preorder Serialization of a Binary Tree
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        stack<string> st;
        int i = 0;
        while(i < n){
            int j = preorder.find(",", i);
            if (j == -1) j = n;
            string curr = preorder.substr(i, j - i);
            if(curr != "#") st.push("A");
            else{
                while (!st.empty() && st.top() == "#"){
                    st.pop();
                    if(st.empty()) return false;
                    st.pop();
                }
                st.push("#");
            }
            if(j==-1) break;
            i = j + 1;
        }
        return st.size() == 1 && st.top() == "#";
    }
};
