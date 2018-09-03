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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> Rnodes;
        queue<TreeNode*> Lnodes;
        Rnodes.push(root->right);
        Lnodes.push(root->left);
        while(!Rnodes.empty() && !Lnodes.empty()){
            TreeNode* leftN = Lnodes.front();
            TreeNode* rightN = Rnodes.front();
            Lnodes.pop();
            Rnodes.pop();
            if(!leftN && rightN)
                return false;
            if(leftN && !rightN)
                return false;
            if(!leftN && !rightN)
                continue;
            if(leftN->val != rightN->val)
                return false;
            Lnodes.push(leftN->left);
            Lnodes.push(leftN->right);
            Rnodes.push(rightN->right);
            Rnodes.push(rightN->left);
        }
        return true;
    }
};
