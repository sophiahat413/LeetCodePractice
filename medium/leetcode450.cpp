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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else{
            if(root->left && root->right){
                TreeNode* min = root->right;
                while(min->left != nullptr)
                    min = min->left;
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
            else{
                TreeNode* newRoot = root->left == nullptr ? root->right : root->left;
                root->left = nullptr;
                root->right = nullptr;
                delete root;
                return newRoot;
            }
        }
        return root;
    }
};
