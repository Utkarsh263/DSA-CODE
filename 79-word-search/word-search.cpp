class Solution {
public:
int rows, cols;
    bool dfs(vector<vector<char>> &board , int r , int c, string &word, int idx){
        if(idx== word.size()){
            return true;
        }

        if(r<0 || r>= rows || c<0 || c>= cols){
            return false;
        }
        if(board[r][c] != word[idx]){
            return false;
        }

        char saved = board[r][c];
        board[r][c] = '#'; // replace character with symbol

        bool found = dfs(board, r + 1, c, word, idx + 1) ||
                     dfs(board, r - 1, c, word, idx + 1) ||
                     dfs(board, r, c + 1, word, idx + 1) ||
                     dfs(board, r, c - 1, word, idx + 1);

        board[r][c] = saved; // restore the character
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(dfs(board, r, c, word , 0)){
                    return true;
                }
            }
        }
        return false;
    }
};