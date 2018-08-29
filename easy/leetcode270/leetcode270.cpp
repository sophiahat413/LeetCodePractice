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
     int DFS(TreeNode * root, double target, double min, int ans){
        if(root == NULL)
            return ans;
        else if(root->val == target)
            return root->val;
        else{
            if((double)abs(root->val - target) < min){
                min = abs(root->val - target);
                ans = root->val;
            }
            if(target > root->val){
                return DFS(root->right, target, min, ans);
            }
            else
                return DFS(root->left, target, min, ans);
        }
    }
    int closestValue(TreeNode * root, double target) {
        // write your code here
        double min = abs(root->val - target);
        if(target > root->val)
            return DFS(root->right, target, min, root->val);
        else if(target < root->val)
            return DFS(root->left, target, min, root->val);
        else
            return root->val;
    }
};
