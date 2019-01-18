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
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode* root){
        if(!root){
            vector<int> res(2, 0);
            return res;
        }
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        vector<int> res(2, 0);
        res[0] = root->val + l[1] + r[1];
        res[1] = max(l[0], l[1]) + max(r[0], r[1]);
        return res;
    }
};
