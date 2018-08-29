/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> nodes;
public:
    void findLeft(TreeNode* root){
        while(root){
            nodes.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode *root) {
        findLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(nodes.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* ans = nodes.top();
        nodes.pop();
        if(ans->right)
            findLeft(ans->right);
        return ans->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
