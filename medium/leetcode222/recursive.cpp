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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int hr = 0, hl = 0;
        TreeNode *l = root, *r = root;
        while(l){
            hl++;
            l = l->left;
        }
        while(r){
            hr++;
            r = r->right;
        }
        if(hl == hr)
            return pow(2, hl) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
