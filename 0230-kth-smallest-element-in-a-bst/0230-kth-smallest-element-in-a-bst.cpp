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
   void inorder(TreeNode* root, int &k, int &r){

    if(root == nullptr || k == 0)
        return;

    inorder(root->left, k, r);

    if(--k == 0){
        r = root->val;
        return;
    }

    inorder(root->right, k, r);
}
    
    int kthSmallest(TreeNode* root, int k) {
        int r =-1;
         inorder(root,k,r);
         return r;
    }
};