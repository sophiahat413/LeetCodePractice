/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(root == nullptr)
            return "";
       
        //ostringstream ss;
        //ss << root->val;
        string str = "[" + to_string(root->val);
        for(auto &n : root->children){
            if(n){
                str += serialize(n);
            }
        }
            
        str += "]";
        //cout<<res<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        auto b = data.begin();
        return myDeserialize(b, data.end());
    }
    Node* myDeserialize(auto &b, const auto e){
        if(b == e)
            return nullptr;
        if(*b == '[')
            b++;
        string curr;
        while(isdigit(*b)){
            curr.push_back(*b++);
        }
        istringstream ss(curr);
        int nodeval = 0;
        ss >> nodeval;
        Node* node = new Node(nodeval);
        while(*b == '['){
            node->children.push_back(myDeserialize(b, e));
        }
        b++;
        return node;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
