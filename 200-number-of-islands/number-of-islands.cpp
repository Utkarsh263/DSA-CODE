class Solution {
public:
    int rows, cols;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<char>>&grid, int r, int c){

        if(r<0 || c<0 || r>=rows || c>=cols || grid[r][c]=='0'){
            return;
        }

        grid[r][c] ='0';

        for(auto &d : dirs){
            dfs(grid, r+d[0], c+d[1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int islands =0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] =='1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};