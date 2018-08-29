class Solution {
private:
    vector<string> ans;
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    void print(TreeNode * root, string cur){
        string t;
        if(root->left == NULL && root->right == NULL){
            t = cur.append(to_string(root->val));
            ans.push_back(t);
        }
        else{
            t = cur.append(to_string(root->val).append("->")) ;
            if(root->left)
                print(root->left,t);
            if(root->right)
                print(root->right,t);
        }
    }
    vector<string> binaryTreePaths(TreeNode * root) {
        // write yourå code here
        if(root == NULL)
            return {};
        print(root, "");
        return ans;
    }
};
