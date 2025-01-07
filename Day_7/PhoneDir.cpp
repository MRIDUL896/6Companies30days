//Phone directory
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool isT;
    char ch;
    vector<TrieNode*> child;
    TrieNode(char ch){
        this -> isT = false;
        this -> ch = ch;
        child.resize(26,nullptr);
    }
};

class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string str){
        TrieNode* curr = root;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(curr->child[ch-'a'] == nullptr){
                TrieNode* node = new TrieNode(ch);
                curr->child[ch-'a'] = node;
            }
            curr = curr->child[ch-'a'];
        }
        curr->isT = true;
    }
    void dfs(TrieNode* curr,string str,vector<string>& ans){
        if(curr == nullptr) return;
        if(curr->isT) ans.push_back(str);
        for(int i=0;i<26;i++){
            if(curr->child[i] != nullptr){
                str += 'a' + i;
                dfs(curr->child[i],str,ans);
                str.pop_back();
            }
        }
    }
    vector<string> find(string str){
        vector<string> ans;
        TrieNode* curr = root;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(curr->child[ch-'a'] == nullptr){
                TrieNode* node = new TrieNode(ch);
                curr->child[ch-'a'] = node;
            }
            curr = curr->child[ch-'a'];
        }
        dfs(curr,str,ans);
        return ans;
    } 
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        Trie t;
        for(int i=0;i<n;i++){
            t.insert(contact[i]);
        }
        vector<vector<string>> ans;
        for(int i=0;i<s.length();i++){
            vector<string> searches = t.find(s.substr(0,i+1));
            if(searches.size() > 0) ans.push_back(searches);
            else ans.push_back({"0"});
        }
        return ans;
    }
};