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
    int depth = INT_MAX;
    void dfs(TreeNode* root , int currDepth){

        if(root == NULL){
            return ;
        }

        if(root->left == NULL && root->right == NULL){
            depth = min(depth, currDepth);
        }

        dfs(root->left , currDepth+1);
        dfs(root->right , currDepth+1);

        
    }
    int minDepth(TreeNode* root) {

        if(root == NULL){
            return 0;
        }
        dfs(root , 1);
        return depth;
    }
};