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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        // If both nodes are smaller 
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left , p , q);
        }

        // If both nodes are greater 
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right , p, q);
        }

        // Split is found , current node is LCA 
        return root;
    }
};