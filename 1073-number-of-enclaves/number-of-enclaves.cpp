class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&visited , vector<vector<int>>&grid){

        visited[r][c] = 1;
        int m = grid.size();
        int n =grid[0].size();

        // Check for all neighbors 
        if(r-1 >= 0 && !visited[r-1][c] && grid[r-1][c] == 1){
            dfs(r-1, c, visited , grid);
        }

         if(r+1 < m && !visited[r+1][c] && grid[r+1][c] == 1){
            dfs(r+1, c, visited , grid);
        }

         if(c-1 >= 0 && !visited[r][c-1] && grid[r][c-1] == 1){
            dfs(r, c-1, visited , grid);
        }

         if(c+1 < n && !visited[r][c+1] && grid[r][c+1] == 1){
            dfs(r, c+1, visited , grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(i==0 || i==m-1 || j==0 || j==n-1){

                    if(grid[i][j] == 1 && !visited[i][j]){
                        dfs(i, j, visited , grid);
                    }
                }
            }
        }

        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};