#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Out of bounds
        if (i < 0 || j < 0) return 0;

        // Obstacle
        if (grid[i][j] == 1) return 0;

        // Start cell
        if (i == 0 && j == 0) return 1;

        // If already computed
        if (dp[i][j] != -1) return dp[i][j];

        // From top and left
        int up = solve(i - 1, j, grid, dp);
        int left = solve(i, j - 1, grid, dp);

        // Store and return
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // If starting cell itself blocked → no paths
        if (grid[0][0] == 1) return 0;

        return solve(m - 1, n - 1, grid, dp);
    }
};
