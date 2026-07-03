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
    TreeNode*construct(vector<int>&inorder, int is , int ie , vector<int>&postorder, int ps , int pe, unordered_map<int,int>&mpp){
        if(is>ie || ps>pe)
        return nullptr;
        TreeNode*root = new TreeNode (postorder[pe]);
        int ri = mpp[root->val];
        int nl = ri- is;
        root->left = construct(inorder,is,ri-1,postorder,ps,ps+nl-1,mpp);
        root->right = construct(inorder,ri+1,ie, postorder, ps+nl, pe-1,mpp );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //inorder - left root right
         // postorder - left right root 
         unordered_map<int,int>mpp;
         for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
         }
         return construct(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }

};