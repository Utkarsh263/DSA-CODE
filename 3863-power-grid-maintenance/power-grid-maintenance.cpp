class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(c + 1);
        for (auto &edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Find connected components using DFS
        vector<int> compId(c + 1, 0);
        int compCount = 0;

        function<void(int, int)> dfs = [&](int node, int id) {
            compId[node] = id;
            for (int nei : adj[node]) {
                if (compId[nei] == 0)
                    dfs(nei, id);
            }
        };

        for (int i = 1; i <= c; ++i) {
            if (compId[i] == 0) {
                compCount++;
                dfs(i, compCount);
            }
        }

        // Step 3: Each component has a sorted set of online stations
        vector<set<int>> compOnline(compCount + 1);
        for (int i = 1; i <= c; ++i)
            compOnline[compId[i]].insert(i);

        vector<bool> online(c + 1, true);
        vector<int> result;

        // Step 4: Process queries
        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int cid = compId[x];

            if (type == 1) {  // Maintenance check
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (!compOnline[cid].empty())
                        result.push_back(*compOnline[cid].begin());  // smallest online id
                    else
                        result.push_back(-1);
                }
            } 
            else if (type == 2) {  // Turn station offline
                if (online[x]) {
                    online[x] = false;
                    compOnline[cid].erase(x);
                }
            }
        }

        return result;
    }
};
