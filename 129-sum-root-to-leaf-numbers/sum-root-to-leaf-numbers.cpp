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
    int ans = 0;
    void pathSum(TreeNode* root , int num){
        if(root == NULL){
            return;
        }

        num = num*10 + root->val;

        if(root->left == NULL && root->right == NULL){
            ans += num;
        }

        pathSum(root->left , num);
        pathSum(root->right , num);
    }
    int sumNumbers(TreeNode* root) {
        
        pathSum(root , 0);
        return ans;
    }
};