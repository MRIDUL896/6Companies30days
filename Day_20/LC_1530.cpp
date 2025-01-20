//1530. Number of Good Leaf Nodes Pairs
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
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
    void dfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj, vector<TreeNode*>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(root);
            return;
        }
        if (root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            dfs(root->left, adj, leaves);
        }
        if (root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            dfs(root->right, adj, leaves);
        }
    }
    
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        vector<TreeNode*> leaves;
        dfs(root, adj, leaves);
        
        int ans = 0;
        for (int i = 0; i < leaves.size(); i++) {
            TreeNode* start = leaves[i];
            unordered_map<TreeNode*, int> dist;
            queue<TreeNode*> q;
            q.push(start);
            dist[start] = 0;
            
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (dist[curr] > distance) break;
                
                for (TreeNode* neigh : adj[curr]) {
                    if (dist.find(neigh) == dist.end()) {
                        dist[neigh] = dist[curr] + 1;
                        q.push(neigh);
                        if (dist[neigh] <= distance && neigh != start && 
                            find(leaves.begin(), leaves.end(), neigh) != leaves.end()) {
                            ans++;
                        }
                    }
                }
            }
        }
        
        return ans / 2; // Each pair is counted twice
    }
};