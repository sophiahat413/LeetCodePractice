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
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    bool find(TreeNode* root, TreeNode * target) {
        if(root == NULL)
            return false;
        if(target->val == root->val)
            return true;
        else{
            if(target->val < root->val){
                return find(root->left, target);
            }
            else
                return find(root->right, target);
        }
    }
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        if(root == NULL)
            return NULL;
        //cout<<"root value "<<root->val<<endl;
        //A B on different side
        if(A->val < root->val && B->val > root->val){
            if(find(root->left, A) && find(root->right, B))
                return root;
            else
                return NULL;
        }
        if(A->val > root->val && B->val < root->val){
            if(find(root->right, A) && find(root->left, B))
                return root;
            else
                return NULL;
        }
        //A B on same side of root
        if(A->val > root->val && B->val > root->val){
            //cout<<"bigger!"<<endl;
            return lowestCommonAncestor(root->right, A, B);
        }
        if(A->val < root->val && B->val < root->val)
            return lowestCommonAncestor(root->left, A, B);
        //A or B equal the root
        if(A->val == root->val){
            //cout<<"hihi"<<endl;
            if(find(root, B))
                return root;
            else 
                return NULL;
        }
        if(B->val == root->val){
            if(find(root, A))
                return root;
            else 
                return NULL;
        }
    }
};
