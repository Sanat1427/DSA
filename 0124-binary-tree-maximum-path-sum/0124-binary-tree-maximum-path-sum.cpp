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
   int path(TreeNode*node, int & maxi){
    if(node==nullptr)
    return 0;
    int lm = max(0,path(node->left,maxi));
    int rm = max(0,path(node->right,maxi));
    maxi= max(maxi,lm+rm+node->val);
    return max(lm,rm)+node->val;
   }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        path(root,maxi);
        return maxi;
    }
};