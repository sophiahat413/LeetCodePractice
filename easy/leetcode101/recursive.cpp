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
    bool helper(TreeNode* Lnode, TreeNode* Rnode){
        if(!Lnode && !Rnode)
            return true;
        else if(!Lnode || !Rnode)
            return false;
        if(Lnode->val != Rnode->val)
            return false;
        return helper(Lnode->left, Rnode->right) && helper(Lnode->right, Rnode->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
    
};
