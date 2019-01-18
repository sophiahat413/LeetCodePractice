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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
      //recursive
        if(root == NULL || root->left == NULL)  return root;
        TreeNode* cur_left = root->left;
        TreeNode* cur_right = root->right;
        TreeNode* newroot = upsideDownBinaryTree(root->left);
        cur_left->left = cur_right;
        cur_left->right = root;
        root->left = NULL;
        root->right = NULL;
        return newroot;
    }
};
