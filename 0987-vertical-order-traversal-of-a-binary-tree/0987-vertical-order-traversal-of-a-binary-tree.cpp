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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       

        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto[node,pos]=q.front();
            q.pop();
            auto[x,y]=pos;
            nodes[x][y].push(node->val);
            if(node->left)
            q.push({node->left,{x-1,y+1}});
            if(node->right)
            q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>>ans;
        for(auto&[x,rows]:nodes){
            vector<int>col;
            for(auto&[y,pq]:rows){
                while(!pq.empty()){
                col.push_back(pq.top());
                pq.pop();
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};