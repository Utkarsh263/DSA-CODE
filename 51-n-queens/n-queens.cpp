class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        unordered_set<int> cols;       // columns
        unordered_set<int> diag;       // (row - col)
        unordered_set<int> antiDiag;   // (row + col)
        
        backtrack(0, n, board, result, cols, diag, antiDiag);
        return result;
    }
    
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result,
                   unordered_set<int>& cols, unordered_set<int>& diag, unordered_set<int>& antiDiag) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (cols.count(col) || diag.count(row - col) || antiDiag.count(row + col))
                continue; // Not safe
            
            // Place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(row - col);
            antiDiag.insert(row + col);
            
            backtrack(row + 1, n, board, result, cols, diag, antiDiag);
            
            // Backtrack
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(row - col);
            antiDiag.erase(row + col);
        }
    }
};
