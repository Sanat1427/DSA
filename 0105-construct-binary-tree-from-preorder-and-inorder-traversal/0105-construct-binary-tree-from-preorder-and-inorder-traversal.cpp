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
     TreeNode*bd(vector<int>&preorder,int ps , int pe , vector<int>&inorder,int is , int ie, unordered_map<int,int>&mpp){
        if(ps>pe||is>ie)
        return nullptr;
        TreeNode*root = new TreeNode (preorder[ps]);
        int ir = mpp[root->val];
        int nl = ir-is;
        root->left = bd(preorder,ps+1,ps+nl,inorder,is,ir-1,mpp);
        root->right = bd(preorder, ps+nl+1,pe,inorder,ir+1, ie,mpp);
        return root;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //inorder(left root  right)
        //preorder(root left right)
        unordered_map<int,int>mpp;
        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return bd(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};