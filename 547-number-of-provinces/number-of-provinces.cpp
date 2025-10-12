class Solution {
public:
    void dfs(int i, vector<int>&visited,vector<vector<int>>& isConnected ){
        int n = isConnected.size();
        for(int j=0; j<n; j++){
            if(isConnected[i][j]==1 && !visited[j]){
                visited[j]=1;  // mark j city as visisted
                dfs(j , visited, isConnected); // explore all connections
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n , 0);
        int provinces =0;

        // Iterating the start node
        for(int i=0; i<n;i++){
            if(!visited[i]){
                visited[i]=1;
                dfs(i, visited , isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};