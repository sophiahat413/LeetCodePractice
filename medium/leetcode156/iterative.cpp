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
        //iterative ->O(1) space
        /*
        cur : record the current root node
        right: record the cur node right sibiling
        parent: record the cur node parent
        next: record the cur node left child
        */
        TreeNode* cur = root;
        TreeNode* right = NULL;
        TreeNode* parent = NULL;
        TreeNode* next = NULL;
        while(cur != NULL){
            next = cur->left;
            cur->left = right;
            right = cur->right;
            cur->right = parent;
            parent = cur;
            cur = next;
        }
        return parent;
    }
};
