//297. Serialize and Deserialize Binary Tree
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                ans += "#,";
                continue;
            }
            ans += to_string(node->val) + ',';
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data[0] == '#') return nullptr;
        vector<string> nodes;
        int i = 0, n = data.size();
        while(i < n){
            int j = data.find(',', i);
            nodes.push_back(data.substr(i, j - i));
            i = j + 1;
        }
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int idx = 1; 
        while(!q.empty() && idx < nodes.size()){
            TreeNode* parent = q.front();
            q.pop();
            if(idx < nodes.size() && nodes[idx] != "#"){
                TreeNode* leftNode = new TreeNode(stoi(nodes[idx]));
                parent->left = leftNode;
                q.push(leftNode);
            }
            idx++;
            if(idx < nodes.size() && nodes[idx] != "#"){
                TreeNode* rightNode = new TreeNode(stoi(nodes[idx]));
                parent->right = rightNode;
                q.push(rightNode);
            }
            idx++;
        }
        return root;
    }
};
