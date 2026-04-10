class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            long long minIndex = q.front().second; // normalize

            long long first, last;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                long long curr = index - minIndex; // 🔥 KEY LINE

                if (i == 0) first = curr;
                if (i == size - 1) last = curr;

                if (node->left)
                    q.push({node->left, 2 * curr});

                if (node->right)
                    q.push({node->right, 2 * curr + 1});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};