class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Direction for moving up down left right
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // Min heaps that stors efforts
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,0}); // {effort, row , column}

        // vector to store each cell efforts
        vector<vector<int>> effort(rows , vector<int>(cols , INT_MAX));
        effort[0][0]=0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int e = curr[0];
            int r= curr[1];
            int c = curr[2];

            if(r == rows-1 && c==cols-1){
                return e;
            }
            // Explore all directions
            for(auto [dr, dc] : dirs){
                int nr = r+dr;
                int nc = c+dc;


                // If out of bound , skip 
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                    continue;

                // Height diff between neighbors 
                int diff = abs(heights[nr][nc]- heights[r][c]);

                int newEffort = max(e, diff);

                if(newEffort < effort[nr][nc]){
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort , nr ,nc});
                }


            }
        }

        return 0;


    }
};