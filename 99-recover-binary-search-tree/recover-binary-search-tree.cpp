/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        nodes.push_back(root);   // store NODE, not value
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i-1]->val > nodes[i]->val) {

                if (!first) {
                    first = nodes[i-1];  // bigger wrong
                }

                second = nodes[i];       // smaller wrong
            }
        }

        // actually fix tree
        swap(first->val, second->val);
    }
};