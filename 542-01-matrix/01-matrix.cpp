class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>visited(m, vector<int>(n, 0));
        vector<vector<int>>dist(m , vector<int>(n, 0));

        queue<pair<pair<int, int>, int>>q;

        // Push all 0's into the queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0 && !visited[i][j]){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;

                }
            }
        }

        // Process the queue 
        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            dist[r][c] = d;
            q.pop();

            if(r-1 >= 0 && !visited[r-1][c]) {
                visited[r-1][c] = 1;
                q.push({{r-1,c}, d+1});
            }

            // Down
            if(r+1 < m && !visited[r+1][c]) {
                visited[r+1][c] = 1;
                q.push({{r+1,c}, d+1});
            }

            // Left
            if(c-1 >= 0 && !visited[r][c-1]) {
                visited[r][c-1] = 1;
                q.push({{r,c-1}, d+1});
            }

            // Right
            if(c+1 < n && !visited[r][c+1]) {
                visited[r][c+1] = 1;
                q.push({{r,c+1}, d+1});
            }
        }

        return dist;
    }
};