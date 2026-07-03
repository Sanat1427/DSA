/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
           vector<int>res;
           unordered_set<TreeNode*>vis;
           q.push(target);
           vis.insert(target);
           int curr =0;
           while(!q.empty()){
            if(curr==k){
                while(!q.empty()){
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }
            int n = q.size();
            for(int i =0;i<n;i++){
                TreeNode*node = q.front();
                q.pop();
                if(node->left && vis.find(node->left)==vis.end()){
                     q.push(node->left);
                     vis.insert(node->left);
                }
                   if(node->right && vis.find(node->right)==vis.end()){
                     q.push(node->right);
                     vis.insert(node->right);
                }
                if(mpp.find(node)!=mpp.end() && vis.find(mpp[node])==vis.end()){
                    q.push(mpp[node]);
                    vis.insert(mpp[node]);
                }
            }
            curr++;
           }      

           return res;
    }
};