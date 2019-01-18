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
    int depth(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int deep = depth(root);
        vector<vector<int>> res(deep, vector<int>{});
        construct(root, res, deep-1);
        return res;
    }
    void construct(TreeNode* root, vector<vector<int>> &res, int level){
        if(!root)   return;
        res[level].push_back(root->val);
        construct(root->left, res, level-1);
        construct(root->right, res, level-1);
    }
};
