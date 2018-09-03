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
    int dfs(TreeNode* root, vector<vector<int>>& result){
        if(root == NULL)
            return 0;
        int level = max(dfs(root->right, result), dfs(root->left, result))+1;
        if(level > result.size()){
            vector<int> leaves;
            result.push_back(leaves);
        }
        result[level-1].push_back(root->val);
        return level;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, result);
        return result;
    }
};
