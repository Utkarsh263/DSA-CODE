class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Mark guards and walls as blocked
        for (auto &g : guards) grid[g[0]][g[1]] = 2;
        for (auto &w : walls) grid[w[0]][w[1]] = 2;

        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        // For each guard, mark visible cells
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (auto &[dr, dc] : directions) {
                int x = r + dr, y = c + dc;
                while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 2) {
                    if (grid[x][y] == 0) grid[x][y] = 1; // mark as guarded
                    x += dr;
                    y += dc;
                }
            }
        }

        int count = 0;
        // Count unguarded empty cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }

        return count;
    }
};
