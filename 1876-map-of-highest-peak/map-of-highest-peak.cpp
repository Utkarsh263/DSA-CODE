class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;  // {{row, column}, height}

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(isWater[i][j] == 1){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int h = q.front().second;

            q.pop();

            // UP
            if(r - 1 >= 0 && !visited[r - 1][c]){
                q.push({{r - 1, c}, h + 1});
                height[r - 1][c] = h + 1;
                visited[r - 1][c] = 1;
            }

            // DOWN
            if(r + 1 < m && !visited[r + 1][c]){
                q.push({{r + 1, c}, h + 1});
                height[r + 1][c] = h + 1;
                visited[r + 1][c] = 1;
            }

            // LEFT
            if(c - 1 >= 0 && !visited[r][c - 1]){
                q.push({{r, c - 1}, h + 1});
                height[r][c - 1] = h + 1;
                visited[r][c - 1] = 1;
            }

            // RIGHT
            if(c + 1 < n && !visited[r][c + 1]){
                q.push({{r, c + 1}, h + 1});
                height[r][c + 1] = h + 1;
                visited[r][c + 1] = 1;
            }
        }

        return height;
    }
};