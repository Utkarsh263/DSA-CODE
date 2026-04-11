class Solution {
public:
    
    // Helper: find minimum in subtree
    TreeNode* findMin(TreeNode* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // ✅ Node found

            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};