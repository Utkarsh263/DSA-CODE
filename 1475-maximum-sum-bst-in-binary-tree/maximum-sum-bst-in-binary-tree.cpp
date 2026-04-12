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
    int maxSum = 0;

    struct Node {
        bool isBST;
        int minVal, maxVal, sum;
    };

    Node solve(TreeNode* root) {
        // Base case
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Node left = solve(root->left);
        Node right = solve(root->right);

        Node curr;

        // Check BST condition
        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            curr.isBST = true;
            curr.sum = root->val + left.sum + right.sum;
            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);

            maxSum = max(maxSum, curr.sum);
        } 
        else {
            curr.isBST = false;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};