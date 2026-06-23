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

    void preorder(TreeNode* root) {

        if(root == NULL) {
            return;
        }

        nodes.push_back(root);

        preorder(root->left);
        preorder(root->right);
    }

    void flatten(TreeNode* root) {

        preorder(root);

        int n = nodes.size();

        for(int i = 0; i < n - 1; i++) {

            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i + 1];
        }

        if(n > 0) {
            nodes[n - 1]->left = NULL;
            nodes[n - 1]->right = NULL;
        }
    }
};