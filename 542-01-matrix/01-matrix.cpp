class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // 286, 1765

        int n = mat.size();
        int m = mat[0].size();

        // Visited Matrix 
        vector<vector<int>>vis(n, vector<int>(m, 0));
        // Distance Matrix
        vector<vector<int>>dist(n, vector<int>(m ,0));

        // Queue for bfs traversal (i, j) , dist
        queue<pair<pair<int, int>, int>>q;

        // First push all 0's in the queue with dist 0 for multi-source bfs 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j} , 0});
                    vis[i][j] = 1;
                }
            }
        }

        // Perform bfs 

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;

            q.pop();

            dist[r][c] = d; // Stored the distance of the nodes being visited

            // Explore all 4 directions 
            
             // UP
            if(r-1 >= 0 && vis[r-1][c] == 0) {
                q.push({{r-1, c}, d+1});
                vis[r-1][c] = 1;
            }

            // DOWN
            if(r+1 < n && vis[r+1][c] == 0) {
                q.push({{r+1, c}, d+1});
                vis[r+1][c] = 1;
            }

            // LEFT
            if(c-1 >= 0 && vis[r][c-1] == 0) {
                q.push({{r, c-1}, d+1});
                vis[r][c-1] = 1;
            }

            // RIGHT
            if(c+1 < m && vis[r][c+1] == 0) {
                q.push({{r, c+1}, d+1});
                vis[r][c+1] = 1;
            }

        }

        return dist;
    }
};