//211. Design Add and Search Words Data Structure
#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char ch;
    bool isT;
    vector<TrieNode*> children;
    TrieNode(char ch){
        this->ch = ch;
        this->isT = false;
        children.resize(26,NULL);
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->children[ch-'a'] == NULL){
                node->children[ch-'a'] = new TrieNode(ch);
            }
            node = node->children[ch-'a'];
        }
        node->isT = true;
    }

    bool searchHelper(string& word, TrieNode* node, int pos) {
        if(pos == word.size()) return node->isT;
        char ch = word[pos];
        if(ch == '.'){
            for(TrieNode* child : node->children){
                if(child != NULL && searchHelper(word, child, pos + 1)){
                    return true;
                }
            }
            return false;
        } else {
            int index = ch - 'a';
            TrieNode* child = node->children[index];
            if (child == NULL) {
                return false; // No matching child for the character
            }
            return searchHelper(word, child, pos + 1);
        }
    }

    bool search(string word) {
       return searchHelper(word, root, 0);
    }
};