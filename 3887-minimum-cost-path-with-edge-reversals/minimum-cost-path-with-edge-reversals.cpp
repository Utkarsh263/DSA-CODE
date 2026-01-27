class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> out(n), in(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            out[u].push_back({v, w});
            in[v].push_back({u, w});
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            // 1️⃣ Normal outgoing edges
            for (auto &[v, w] : out[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }

            // 2️⃣ Reverse any incoming edge
            for (auto &[v, w] : in[u]) {
                long long newCost = cost + 2LL * w;
                if (dist[v] > newCost) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }

        return dist[n-1] == INF ? -1 : (int)dist[n-1];
    }
};
