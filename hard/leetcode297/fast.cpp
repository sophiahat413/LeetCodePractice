/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string res = "";
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "#";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#")
            return nullptr;
        stringstream s(data);
        return myDeserialize(s);  
    }
    TreeNode* myDeserialize(stringstream &data){
        string str;
        getline(data, str, ',');
        if(str == "#"){
            return nullptr;
        }
        else{
            TreeNode* node = new TreeNode(stoi(str));
            node->left = myDeserialize(data);
            node->right = myDeserialize(data);
            return node;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
