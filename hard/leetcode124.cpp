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
    int maxToRoot(TreeNode* root, int &res){
        if(!root)   return 0;
        int l = max(0, maxToRoot(root->left, res));
        int r = max(0, maxToRoot(root->right, res));
        res = max(res, root->val+l+r);
        return root->val + max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxToRoot(root, res);
        return res;
    }
};
