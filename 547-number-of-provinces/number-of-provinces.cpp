class Solution {
public:
    void dfs(int node , vector<vector<int>>&adj , vector<bool>&visited){

        visited[node] = true; // Mark the node as visited 

        // Visit its neighbors 
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // Building the  Graph from the matrix 
        int n = isConnected.size();
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Building the Visited array to mark the city tracked 
        vector<bool>visited(n, false);

        // Traverse the Graph 
        int provinces = 0;
        for(int i=0; i<n; i++){

            if(!visited[i]){
                provinces++;
                dfs(i, adj, visited);
            }
            
        }

        return provinces;
        
    }
};