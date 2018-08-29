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
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        if((A->val < root->val) && (B->val < root->val))
            return lowestCommonAncestor(root->left, A, B);
        if((A->val > root->val) && (B->val > root->val))
            return lowestCommonAncestor(root->right, A, B);
        else
            return root;
    }
};
