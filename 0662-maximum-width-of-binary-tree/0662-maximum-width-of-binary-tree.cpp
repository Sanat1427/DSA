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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
           int ans =0;
     while (!q.empty()) {
    int n = q.size();
    long long mini = q.front().second;

    long long first = 0, last = 0;

    for (int i = 0; i < n; i++) {
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        long long cur = it.second - mini;

        if (i == 0) first = cur;
        if (i == n - 1) last = cur;

        if (node->left)
            q.push({node->left, 2 * cur + 1});

        if (node->right)
            q.push({node->right, 2 * cur + 2});
    }

    ans = max(ans, (int)(last - first + 1));
}
        return ans;
        
    }
};