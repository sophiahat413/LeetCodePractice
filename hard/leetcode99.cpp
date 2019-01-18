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
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* pre = new TreeNode(INT_MIN);
public:
    void traverse(TreeNode* root){
        if(!root)
            return;
        traverse(root->left);
        if(first == nullptr && pre->val >= root->val)
            first = pre;
        if(first != nullptr && pre->val >= root->val)
            second = root;
        pre = root;
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
