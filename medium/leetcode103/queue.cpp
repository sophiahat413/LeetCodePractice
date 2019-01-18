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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return vector<vector<int>>();
        queue<TreeNode*> nodes;
        vector<vector<int>> res;
        nodes.push(root);
        bool fromRight = false;
        //i -> i // i -> line size - 1 - i
        while(!nodes.empty()){
            int n = nodes.size();
            vector<int> line(n);
            for(int i = 0; i < n; i++){
                TreeNode* tmp = nodes.front();
                nodes.pop();
                int index = (fromRight) ? (n - 1 - i) : i;
                line[index] = tmp->val;
                if(tmp->left)
                    nodes.push(tmp->left);
                if(tmp->right)
                    nodes.push(tmp->right);
            }
            fromRight = !fromRight;
            res.push_back(line);
        }
        return res;
    }
};
