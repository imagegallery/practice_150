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
public:
    void util_serialize(TreeNode* root, ostringstream& out){
        if(root == NULL)
            out << "# ";
        else{
            out << root->val << ' ';
            util_serialize(root->left, out);
            util_serialize(root->right, out);
        }
    }
    TreeNode* util_deserialize(istringstream &in){
        string val;
        in >> val;
        //cout << val << endl;
        if(val == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = util_deserialize(in);
        root->right = util_deserialize(in);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        util_serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return util_deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));