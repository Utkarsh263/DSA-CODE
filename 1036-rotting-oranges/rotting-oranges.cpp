class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size(); 
        int n = grid[0].size();

        // Make Visited Matrix 
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Use multi source bfs traversal 
        queue<pair<pair<int, int>,int>>q;  // {(row, col), time}

        int fresh = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 2){
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        // Traverse the Graph 
        int time = 0;
        int ans = 0;

        while(!q.empty()){

            int r= q.front().first.first;
            int c = q.front().first.second;
            time = q.front().second;

            q.pop();

            ans = max(ans , time);

            // Explore all 4 directions 

            // Up direction 
            if(r-1 >= 0 && !visited[r-1][c] && grid[r-1][c] == 1){
                q.push({{r-1, c}, time+1});
                visited[r-1][c] = 1;
                fresh--;
            }

            // Down direction 

            if(r+1 < m && !visited[r+1][c] && grid[r+1][c] == 1){
                q.push({{r+1, c}, time+1});
                visited[r+1][c] = 1;
                fresh--;
            }

            // Left direction

            if(c-1 >= 0 && !visited[r][c-1] && grid[r][c-1] == 1){
                q.push({{r, c-1}, time+1});
                visited[r][c-1] = 1;
                fresh--;
            }

            // Right direction 
            if(c+1 < n && !visited[r][c+1] && grid[r][c+1]==1){
                q.push({{r, c+1}, time+1});
                visited[r][c+1] = 1;
                fresh--;
            }
        }

        if(fresh > 0){ // If any fresh orange left , its impossible to rot all oranges  
            return -1;
        }

        return time;
    }
};