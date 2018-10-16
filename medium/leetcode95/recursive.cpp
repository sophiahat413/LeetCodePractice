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
    vector<TreeNode*> build(int from, int to){
        vector<TreeNode*> res;
        if(from > to)
            res.push_back(0);
        else if(from == to)
            res.push_back(new TreeNode(from));
        else{
            for(int i = from; i <= to; i++){
                vector<TreeNode*> l = build(from, i-1);
                vector<TreeNode*> r = build(i+1, to);
                for(int q = 0; q < l.size(); q++){
                    for(int k = 0; k < r.size(); k++){
                        TreeNode* newRoot = new TreeNode(i);
                        newRoot->left = l[q];
                        newRoot->right = r[k];
                        res.push_back(newRoot);
                    }
                } 
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>();
        return build(1, n);
    }
};
