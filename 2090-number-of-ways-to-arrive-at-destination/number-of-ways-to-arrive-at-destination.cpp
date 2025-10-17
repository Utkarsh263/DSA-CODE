class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 +7;

        // Step : Build adjancency list 
        vector<pair<int, int>>adj[n];
        for(auto &r: roads){
            int u=r[0] , v=r[1] , t=r[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u,t});
        }

        // Initialisation 
         vector<long long>dist (n ,LLONG_MAX);
         vector<long long>ways(n ,0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>> , greater<>>pq;

        dist[0]=0;
        ways[0]=1;

        pq.push({0,0}); // {dist  , node};

        while(!pq.empty()){
            auto[d,u] = pq.top();
            pq.pop();

            if(d > dist[u]){
                continue;
            }

            for(auto &[v,t] :adj[u]){
                long long newDist = d+t;

                if(newDist < dist[v]){
                    dist[v]= newDist;
                    ways[v]= ways[u];
                    pq.push({newDist , v});
                }else if(newDist == dist[v]){
                    ways[v]= (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1] %MOD;
    }
};