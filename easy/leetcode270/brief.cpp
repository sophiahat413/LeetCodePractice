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
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        int a = root->val;
        auto kid = (target < a) ? root->left : root->right;
        if(!kid) return a;
        int b = closestValue(kid, target);
        return abs(a - target) < (double)abs(b - target) ? a : b; 
    }
};
