class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n , 0);

        // Build the reversed graph
        for(int u=0; u<n; u++){
            for(int v : graph[u]){
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        vector<int> safe;
        queue<int>q;

        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node= q.front();
            q.pop();
            safe.push_back(node);

            for(int prev : revGraph[node]){
                indegree[prev]--;
                if(indegree[prev]==0){
                    q.push(prev);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};