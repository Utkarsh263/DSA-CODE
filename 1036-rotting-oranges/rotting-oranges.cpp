class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int,int>, int>> q; // ((row,col), time)
        int fresh = 0;
        
        // Step 1: collect all rotten oranges and count fresh
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == 2)
                    q.push({{i, j}, 0});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        // Directions: up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        int time = 0;

        // Step 2: BFS
        while(!q.empty()) {
            auto [cell, t] = q.front();
            q.pop();
            int x = cell.first, y = cell.second;
            time = max(time, t);

            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({{nx, ny}, t + 1});
                }
            }
        }

        // Step 3: check remaining fresh oranges
        return (fresh == 0) ? time : -1;
    }
};
