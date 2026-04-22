class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // Cannot start or cannnot end the path 
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        // queue = {row , col , dist}
        queue<pair<pair<int , int>, int>>q;

        q.push({{0,0} , 1});

        grid[0][0] = 1;

        while(!q.empty()){

            auto it = q.front();
            q.pop();


            int x = it.first.first;
            int y = it.first.second;
            int dist = it.second;

            // if we have reached the destination 

            if(x == n-1 && y== n-1){
                return dist;
            }

             // DOWN
            if(x+1 < n && grid[x+1][y] == 0) {
                grid[x+1][y] = 1;
                q.push({{x+1, y}, dist+1});
            }

            // UP
            if(x-1 >= 0 && grid[x-1][y] == 0) {
                grid[x-1][y] = 1;
                q.push({{x-1, y}, dist+1});
            }

            // RIGHT
            if(y+1 < n && grid[x][y+1] == 0) {
                grid[x][y+1] = 1;
                q.push({{x, y+1}, dist+1});
            }

            // LEFT
            if(y-1 >= 0 && grid[x][y-1] == 0) {
                grid[x][y-1] = 1;
                q.push({{x, y-1}, dist+1});
            }

            // DIAGONAL DOWN-RIGHT
            if(x+1 < n && y+1 < n && grid[x+1][y+1] == 0) {
                grid[x+1][y+1] = 1;
                q.push({{x+1, y+1}, dist+1});
            }

            // DIAGONAL DOWN-LEFT
            if(x+1 < n && y-1 >= 0 && grid[x+1][y-1] == 0) {
                grid[x+1][y-1] = 1;
                q.push({{x+1, y-1}, dist+1});
            }

            // DIAGONAL UP-RIGHT
            if(x-1 >= 0 && y+1 < n && grid[x-1][y+1] == 0) {
                grid[x-1][y+1] = 1;
                q.push({{x-1, y+1}, dist+1});
            }

            // DIAGONAL UP-LEFT
            if(x-1 >= 0 && y-1 >= 0 && grid[x-1][y-1] == 0) {
                grid[x-1][y-1] = 1;
                q.push({{x-1, y-1}, dist+1});
            }
        }

        return -1;
    }
};