class Solution {
public:
    int rows, cols;
    bool dfs(int idx , vector<vector<char>>&board , string word, int r, int c){

        // Base case 
        if(idx == word.size()){
            return true;
        }

        // False condition 
        if (r < 0 || c < 0 ||r >= rows || c >= cols || board[r][c] != word[idx]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // Mark as visited 

        bool found = dfs(idx+1 , board, word , r+1 , c) || dfs(idx+1 , board, word , r-1 , c) || dfs(idx+1 , board, word , r , c+1) || dfs(idx+1 , board, word , r , c-1);

        // Backtrack 
        board[r][c] = temp;

        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        rows = board.size();
        cols = board[0].size();

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(dfs(0, board , word, i, j)){
                    return true;
                }
            }
        }

        return false;
    }
};