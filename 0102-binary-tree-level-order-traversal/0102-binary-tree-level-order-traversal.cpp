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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        TreeNode*node=root;
        q.push(node);
        if(node==nullptr)
        return ans;
        while(!q.empty()){
            int n = q.size();
            vector<int>levels;
            for(int i =0;i<n;i++){
                node= q.front();
                q.pop();
                levels.push_back(node->val);
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                q.push(node->right);
            }
            ans.push_back(levels);
        }
        return ans;
    }
};