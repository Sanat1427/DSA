/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
        
    }
    int dfs(TreeNode*root){
        if(root==nullptr)
        return 0;
        int lefth= dfs(root->left);
        if(lefth==-1)return -1;
        int righth=dfs(root->right);
        if(righth==-1)return -1;
        if(abs(lefth-righth)>1)
          return -1;
          return max(lefth,righth)+1;
    }
};