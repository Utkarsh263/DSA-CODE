class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // Distance matrix (minimum effort to reach each cell)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // Min heap: (effort, row, col)
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        
        pq.push({0, 0, 0}); // effort = 0 at start
        dist[0][0] = 0;
        
        // 4 directions
        vector<pair<int,int>> dir = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };
        
        while (!pq.empty()) {
            auto [eff, r, c] = pq.top();
            pq.pop();
            
            // If destination reached
            if (r == n - 1 && c == m - 1)
                return eff;
            
            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int diff = abs(heights[r][c] - heights[nr][nc]);
                    
                    int newEffort = max(eff, diff);
                    
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        
        return 0; // fallback (won’t really happen)
    }
};