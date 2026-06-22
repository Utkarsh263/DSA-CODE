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
    int height(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        if(leftHeight == -1){
            return -1;
        }

        int rightHeight = height(root->right);
        if(rightHeight == -1){
            return -1;
        }

        if(abs(leftHeight - rightHeight) > 1){
            return -1;
        }

        return 1+max(leftHeight , rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        
        return height(root) != -1;
    }
};

// Brute Force approach 
// class Solution {
// public:
//     int height(TreeNode* root){

//         if(root == NULL){
//             return 0;
//         }

//         int left = height(root->left);
//         int right = height(root->right);

//         return 1+max(left , right);
//     }
//     bool isBalanced(TreeNode* root) {
        
//         if(root == NULL){
//             return true;
//         }

//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);

//         if(abs(leftHeight - rightHeight) > 1){
//             return false;
//         }

//         return isBalanced(root->left) && isBalanced(root->right);
//     }
// };