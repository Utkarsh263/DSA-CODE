class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n , -1);
        queue<int> q;

        for(int i=0; i<n; i++){
            if(color[i]==-1){  // not colored yet
                color[i]=0;
                q.push(i);
            }

            while(!q.empty()){
                int node= q.front();
                q.pop();

                for(auto neighbors : graph[node]){
                    if(color[neighbors]==-1){
                        color[neighbors] = 1-color[node];
                        q.push(neighbors);
                    }else if(color[neighbors]== color[node]){
                        return false;
                    }
                }
            } 
        }
        return true;
    }
};