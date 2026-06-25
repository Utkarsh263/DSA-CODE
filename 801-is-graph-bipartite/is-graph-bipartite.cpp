class Solution {
public:
    bool dfs(int node , int color, vector<vector<int>>&graph, vector<int>&colors){

        colors[node] = color;

        // Visit all the neighbour and color them 
        for(int neighbour : graph[node]){

            if(colors[neighbour] == -1){

                if(!dfs(neighbour , 1-color , graph , colors)){
                    return false;
                }
            }else if(colors[neighbour] == color){
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>colors(n , -1);

        for(int i=0; i<n; i++){

            if(colors[i] == -1){

                if(!dfs(i, 0, graph , colors)){
                    return false;
                }
            }
        }

        return true;
    }
};