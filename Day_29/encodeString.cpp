/*Run Length Encoding

Given a string s, Your task is to complete the function encode that returns 
the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the 
string which is to be encoded and returns the encoded string.*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
  public:
    string encode(string s) {
        int n = s.length();
        string encoding = "";
        int count = 1;
        char prev = s[0];
        for(int i=1;i<n;i++){
            if(s[i] == prev){
                count++;
            }else{
                encoding += prev;
                encoding += to_string(count);
                count = 1;
                prev = s[i];
            }
        }
        encoding += prev;
        encoding += to_string(count);
        return encoding;
    }
};