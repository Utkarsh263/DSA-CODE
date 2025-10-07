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
    int i=0;
    TreeNode* build(vector<int> &preorder, int minVal , int maxVal){
        if(i== preorder.size()){
            return NULL;
        }

        int val = preorder[i];
        if(val <minVal || val > maxVal){
            return NULL;
        }

        TreeNode* root = new TreeNode(val);
        i++;

        root->left = build(preorder, minVal , val);
        root->right = build(preorder , val , maxVal);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder ,INT_MIN , INT_MAX);
    }
};