class Solution {
public:
    bool isCycleDFS(int src , vector<bool>&vis , vector<bool>&recPath, vector<vector<int>>&edges , stack<int>&st){

        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u==src){
                if(!vis[v]){
                    if(isCycleDFS(v , vis, recPath , edges , st)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }

        recPath[src] = false;

        st.push(src);

        return false;

    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        
        vector<bool>vis(n , false);
        vector<bool>recPath(n , false);
        stack<int>st;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis , recPath , edges , st)){
                    return {};
                }
            }
        }

        // No cycle exists 

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

    }
};