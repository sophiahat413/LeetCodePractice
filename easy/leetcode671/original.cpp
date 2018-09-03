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
    int second = INT_MAX;
public:
    bool hasChild(TreeNode* root){
        if(!root->left)
            return false;
        return true;
    }
    void dfs(TreeNode* root){
        if(!root->left)
            return;
        if(root->val == root->right->val && root->val == root->left->val){
            dfs(root->left);
            dfs(root->right);
        }
        else if(root->val == root->right->val){ 
            if(root->left->val < second)
                second = root->left->val;
            if(hasChild(root->right))
                dfs(root->right);
        }
        else if(root->val == root->left->val){
            if(root->right->val < second)
                second = root->right->val;
            if(hasChild(root->left))
                dfs(root->left);
        }   
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root->right || (root->val == root->right->val && root->val == root->left->val))
            return -1;
        dfs(root);
        return second;
    }
};
