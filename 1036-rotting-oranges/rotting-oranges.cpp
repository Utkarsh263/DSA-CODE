class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        // Visited matrix 
        vector<vector<int>>vis(n, vector<int>(m, 0));

        //Queue for BFS Traversal 
        queue<pair<pair<int, int>, int>>q;  //{(row, col), time}

        int fresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){  // Rotten Orange
                    q.push({{i, j}, 0});
                    vis[i][j] == 1;
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();
            time = max(time, t);
            // Explore  directions

            if(r-1 >= 0 && !vis[r-1][c] && grid[r-1][c] == 1){
                q.push({{r-1, c} , t+1});
                vis[r-1][c] = 1;
                fresh--;
            }

            if(r+1 < n && grid[r+1][c] == 1 && vis[r+1][c] == 0) {
                q.push({{r+1, c}, t+1});
                vis[r+1][c] = 1;
                fresh--;
            }

            // LEFT
            if(c-1 >= 0 && grid[r][c-1] == 1 && vis[r][c-1] == 0) {
                q.push({{r, c-1}, t+1});
                vis[r][c-1] = 1;
                fresh--;
            }

            // RIGHT
            if(c+1 < m && grid[r][c+1] == 1 && vis[r][c+1] == 0) {
                q.push({{r, c+1}, t+1});
                vis[r][c+1] = 1;
                fresh--;
            }


        }

        if(fresh > 0){
            return -1;
        }

        return time;
    }
};