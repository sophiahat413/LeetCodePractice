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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        verify(root, res);
        return res;
    }
    bool verify(TreeNode* root, int &cnt){
        if(!root)   return true;
        auto isLeft = verify(root->left, cnt);
        auto isRight = verify(root->right, cnt);
        if(isLeft && isRight && ((root->left == nullptr) || (root->val == root->left->val)) && ((root->right == nullptr) || (root->val == root->right->val))){
            cnt++;
            return true;
        }
        return false;
    }
};
