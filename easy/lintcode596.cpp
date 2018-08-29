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
    TreeNode * result = nullptr;
    int min = INT_MAX;
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    int helper(TreeNode * root){
        if(root == NULL)
            return 0;
        else{
           int lSum = helper(root->left);
           int rSum = helper(root->right);
           if((root->val + rSum + lSum) < min){
               min = root->val + rSum + lSum;
               result = root;
           }
           return root->val + rSum + lSum;
        }
    }
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
       helper(root);
       return result;
    }
};
