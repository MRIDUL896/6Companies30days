/*Number following a pattern 
Given a pattern containing only I's and D's. I for increasing and D for decreasing. 
Devise an algorithm to print the minimum number following that pattern. 
Digits from 1-9 and digits can't repeat.*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string S){
        stack<int> st;
        int counter = 1;
        string ans = "";
        for(char &ch : S){
            st.push(counter++);
            if(ch == 'D') continue;
            else{
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(counter);
        if(!st.empty()){
            while(!st.empty()){
                ans += to_string(st.top());
                st.pop();
            }
        }
        return ans;
    }
};
