//1600. Throne Inheritance
#include<iostream>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Node{
    public:
    string name;
    bool isAlive;
    vector<Node*> children;
    Node(string name){
        this->name = name;
        this->isAlive = true;
    }
};
class ThroneInheritance {
public:
    Node* root;
    unordered_map<string,Node*> mp;
    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        mp[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node* parent = mp[parentName];
        Node* child = new Node(childName);
        parent->children.push_back(child);
        mp[childName] = child;
    }
    
    void death(string name) {
        mp[name]->isAlive = false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            if(node->isAlive) ans.push_back(node->name);
            for(int i=node->children.size()-1;i>=0;i--){
                st.push(node->children[i]);
            }
        }
        return ans;
    }
};