//1373. Maximum Sum BST in Binary Tree
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class info{
    public:
    bool isBst;
    int sum,lb,ub;
};

class Solution {
public:
    info dfs(TreeNode* root,int &maxSum){
        if(!root){
            info temp;
            temp.sum = 0;
            temp.isBst = 1;
            temp.lb = INT_MAX;
            temp.ub = INT_MIN;
            return temp;
        }
        info nodeInfo;
        info left = dfs(root->left,maxSum);
        info right = dfs(root->right,maxSum);
        nodeInfo.lb = min(left.lb,root->val);
        nodeInfo.ub = max(right.ub,root->val);
        if(left.isBst && right.isBst && root->val > left.ub && root->val < right.lb){
            nodeInfo.sum = right.sum + left.sum + root->val;
            nodeInfo.isBst = 1;
            maxSum = max(maxSum,nodeInfo.sum);
            return nodeInfo;
        }else{
            nodeInfo.sum = 0;
            nodeInfo.isBst = 0;
        }
        return nodeInfo;
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        info ans = dfs(root,maxSum);
        return maxSum;
    }
};