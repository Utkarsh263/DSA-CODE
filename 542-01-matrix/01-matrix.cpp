class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m , vector<int>(n , -1));
        queue<pair<int , int>>q;

        // pushing all 0 inside at once 
        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i ,j});
                }
            }
        }

        vector<pair<int , int>>dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        // BFS
        while(!q.empty()){
            auto[x, y] = q.front();
            q.pop();

            for(auto[dx, dy] : dirs){
                int nx = x+dx;
                int ny = y+dy;

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && dist[nx][ny] == -1){
                    dist[nx][ny]= dist[x][y]+1;
                    q.push({nx , ny});
                }
            }
        }
        return dist;
    }
};