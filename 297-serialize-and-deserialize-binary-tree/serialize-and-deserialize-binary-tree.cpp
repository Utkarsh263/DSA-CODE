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

    void preorder(TreeNode* root, string& s) {

        if(root == NULL) {
            s += "N ";
            return;
        }

        s += to_string(root->val) + " ";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s;

        preorder(root, s);

        return s;
    }

    TreeNode* build(stringstream& ss) {

        string val;
        ss >> val;

        if(val == "N") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        return build(ss);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));