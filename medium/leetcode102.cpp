/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if(!root)
            return {};
        else{
            queue<TreeNode*> que;
            que.push(root);
            while(!que.empty()){
                vector<int> level;
                int q_count = que.size();
                //cout<<que.size()<<endl;
                for(int i = 0; i<q_count; i++){
                    TreeNode* t = que.front();
                    if(t->left)
                        que.push(t->left);
                    if(t->right)
                        que.push(t->right);
                    que.pop();
                    level.push_back(t->val);
                }
                result.push_back(level);
            }
        }
        return result;
    }
};
