//2385. Amount of Time for Binary Tree to Be Infected
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,int start){
        if(!root) return NULL;
        TreeNode* left = NULL,*right = NULL;
        if(root->left){
            left = dfs(root->left,parent,start);
            parent[root->left] = root;
        }
        if(root->right){
            right = dfs(root->right,parent,start);
            parent[root->right] = root;
        }
        if(root->val == start) return root;
        if(left) return left;
        return right;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* st = dfs(root,parent,start);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(st);
        vis[st] = true;
        int timer = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left] = true;
                    q.push(node->left);
                } 
                if(node->right && !vis[node->right]){
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                } 
            }
            // cout<<timer<<" ";
            if(!q.empty()) timer++;
        }
        return timer;
    }
};