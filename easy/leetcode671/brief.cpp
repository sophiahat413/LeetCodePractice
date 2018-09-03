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
    int minimal(TreeNode* root, int val){
        if(!root)
            return -1;
        if(root->val != val)
            return root->val;
        int Lval = minimal(root->left, val), Rval = minimal(root->right, val);
        if(Lval == -1)
            return Rval;
        if(Rval == -1)
            return Lval;
        return min(Rval, Lval);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        return minimal(root, root->val);
    }
};
