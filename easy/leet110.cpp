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
    
    int getDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        int lDepth = getDepth(root->left);
        int rDepth = getDepth(root->right);
        if(lDepth == -1 || rDepth == -1 || abs(lDepth - rDepth) > 1)
            return -1;
        return 1+max(lDepth, rDepth);
    } 
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
};
