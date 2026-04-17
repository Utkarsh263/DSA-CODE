class Solution {
public:
    int m , n;

    void dfs(int i, int j, vector<vector<char>>& board) {
        // base condition
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O')
            return;

        // mark as safe
        board[i][j] = 'T';

        // explore 4 directions
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }
    
    void solve(vector<vector<char>>& board) {
        
        n = board.size();
        m = board[0].size();

        // Traverse the row boundary 
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                dfs(0, j, board);
            }
            if(board[n-1][j] == 'O'){
                dfs(n-1 , j, board);
            }
        }

        // Traverse the column boundary 
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board);
            }
            if(board[i][m-1] == 'O'){
                dfs(i , m-1, board);
            }
        }

        // Flip surrounded + restore safe 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};