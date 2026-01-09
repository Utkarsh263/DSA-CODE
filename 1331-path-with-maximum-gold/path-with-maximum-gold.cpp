class Solution {
public:
    int rows, cols;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(vector<vector<int>>&grid , int r, int c){

        if(r<0 || c<0 ||r >= rows || c>=cols || grid[r][c]==0){
            return 0;
        }

        int gold = grid[r][c];
        grid[r][c]= 0; //Mark as visited

        int best = 0;
        for(auto &d : dirs){
            best = max(best, dfs(grid , r+d[0], c+d[1]));
        }

        grid[r][c] = gold;

        return gold + best;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int maxGold =0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] > 0){
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }

        return maxGold;
    }
};