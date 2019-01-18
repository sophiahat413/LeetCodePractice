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
    int findLongest(TreeNode* root, int &res){
        if(!root)   return 0;
        int l = findLongest(root->left, res);
        int r = findLongest(root->right, res);
        int pl = 0, pr = 0;
        if(root->left && root->val == root->left->val)  pl = l+1;
        if(root->right && root->val == root->right->val)    pr = r+1;
        res = max(res, pl+pr);
        return max(pl, pr);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)   return 0;
        int res = 0;
        findLongest(root, res);
        return res;
    }
};
