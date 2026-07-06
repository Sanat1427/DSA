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
     void func(TreeNode*node, vector<int>& ans){
        if(!node)
        return ;
        func(node->left,ans);
        ans.push_back(node->val);
        func(node->right,ans);
     }
      vector<int>inorder(TreeNode*root){
        vector<int>ans;
        func(root,ans);
        return ans;
      }
    bool findTarget(TreeNode* root, int k) {
        vector<int>s= inorder(root);
        int  l  =0;
        int r = s.size()-1;
        while(l<r){
            int sum = s[l]+s[r];
            if(sum==k)
            return true;
            else if (sum<k)
            l++;
            else
            r--;
        }
        return false;

    }
};