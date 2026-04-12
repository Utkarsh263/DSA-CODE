class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> height(n, vector<int>(m, 0));

        // queue: {{row, col}, height}
        queue<pair<pair<int,int>, int>> q;

        // 🔹 Step 1: push all water cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // 🔹 Step 2: BFS
        while(!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int h = q.front().second;

            q.pop();

            height[r][c] = h;

            // 🔥 4 directions

            // UP
            if(r-1 >= 0 && vis[r-1][c] == 0) {
                q.push({{r-1, c}, h+1});
                vis[r-1][c] = 1;
            }

            // DOWN
            if(r+1 < n && vis[r+1][c] == 0) {
                q.push({{r+1, c}, h+1});
                vis[r+1][c] = 1;
            }

            // LEFT
            if(c-1 >= 0 && vis[r][c-1] == 0) {
                q.push({{r, c-1}, h+1});
                vis[r][c-1] = 1;
            }

            // RIGHT
            if(c+1 < m && vis[r][c+1] == 0) {
                q.push({{r, c+1}, h+1});
                vis[r][c+1] = 1;
            }
        }

        return height;
    }
};