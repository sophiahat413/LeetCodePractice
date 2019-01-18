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
    void findLarge(TreeNode* root, int level, vector<int>& res){
        if(root == nullptr)
            return;
        if(res.size() < level + 1){
            res.push_back(root->val);
        }
        else{
            if(res[level] < root->val)
                res[level] = root->val;
        }
        findLarge(root->left, level+1, res);
        findLarge(root->right, level+1, res);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> res;
        findLarge(root,0, res);
        return res;
    }
};
