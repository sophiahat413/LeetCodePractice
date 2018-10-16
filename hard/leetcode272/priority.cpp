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
    void dfs(TreeNode* root, priority_queue<pair<double, int>>&nodes, double target, int k){
        if(!root)
            return;
        nodes.push(make_pair(fabs(target - (double)root->val), root->val));
        if(nodes.size() > k)
            nodes.pop();
        dfs(root->left, nodes, target, k);
        dfs(root->right, nodes, target, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(!root)
            return vector<int>();
        priority_queue<pair<double, int>> nodes;
        dfs(root, nodes, target, k);
        vector<int> res;
        while(!nodes.empty()){
            cout<<"hihi "<<nodes.top().second<<endl;
            res.push_back(nodes.top().second);
            nodes.pop();
        }
        return res;
    }
};
