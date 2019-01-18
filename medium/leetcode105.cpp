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
    TreeNode* helper(vector<int>& preorder, int pstart, vector<int>& inorder, int istart, int iend){
        if(istart > iend)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pstart]);
        int k;
        for(int i = istart; i <= iend; i++){
            if(inorder[i] == root->val){
                k = i;
                break;
            }
        }
        root->left = helper(preorder, pstart+1, inorder, istart, k-1);
        root->right = helper(preorder, pstart+k-istart+1, inorder, k+1, iend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        return helper(preorder, 0, inorder, 0, inorder.size()-1);
    }
};
