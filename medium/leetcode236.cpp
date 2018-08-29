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
    TreeNode* find(TreeNode* root, TreeNode* A, TreeNode* B){
        if(root == A || root == B || root == NULL)
            return root;
        TreeNode* left = find(root->left, A, B);
        TreeNode* right = find(root->right, A, B);
        if(left && right)
            return root;
        else
            return left ? left : right;
    }
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        return find(root, A, B);
    }
};
