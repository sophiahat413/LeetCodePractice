/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
    private:
    TreeNode* lastNode = NULL;
    public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
        if(root == NULL)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(lastNode && lastNode->val >= root->val)
            return false;
        lastNode = root;
        return isValidBST(root->right);
    }
};
