class Solution {
public:
    void dfs(int r, int c ,vector<vector<int>>&visited, vector<vector<char>>&board){

        visited[r][c] = 1;

        int m = board.size();
        int n = board[0].size();

        // Run dfs to neighbours 
        if(r-1>=0 && !visited[r-1][c] && board[r-1][c] == 'O'){
            dfs(r-1, c, visited , board);
        }

        if(r+1 < m && !visited[r+1][c] && board[r+1][c] == 'O'){
            dfs(r+1, c, visited , board);
        }

        if(c-1 >= 0 && !visited[r][c-1] && board[r][c-1] == 'O'){
            dfs(r, c-1 , visited , board);
        }

        if(c+1 < n && !visited[r][c+1] && board[r][c+1] == 'O'){
            dfs(r, c+1 , visited , board);
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>visited(m, vector<int>(n ,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(i==0 || i== m-1 || j==0 || j==n-1){
                    
                    if(board[i][j] == 'O' && !visited[i][j]){
                        dfs(i, j, visited , board);
                    }
                }
            }
        }

        // Mark remainig unvisted O as X 

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};