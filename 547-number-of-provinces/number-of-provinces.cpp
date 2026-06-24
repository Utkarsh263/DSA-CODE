class Solution {
public:
    void dfs(int node , vector<vector<int>>&adj , vector<bool>&visited){

        visited[node] = true;

        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>>adj(n);

        // Build the Graph from the matrix 

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && isConnected[i][j] != 0){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int provinces = 0;
        vector<bool>visited(n, false);

        // Traverse the Graph and count number of provinces 

        for(int i=0; i<n; i++){
            if(!visited[i]){
                provinces++;
                dfs(i, adj, visited);
            }
        }

        return provinces;
    }
};