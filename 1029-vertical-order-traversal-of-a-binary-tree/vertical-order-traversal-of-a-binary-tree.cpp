class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map: column -> {row -> multiset of values}
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q; // node, {x, y}
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            nodes[x][y].insert(node->val);
            
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
        
        vector<vector<int>> ans;
        
        for (auto& col : nodes) {
            vector<int> colVals;
            for (auto& row : col.second) {
                colVals.insert(colVals.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(colVals);
        }
        
        return ans;
    }
};
