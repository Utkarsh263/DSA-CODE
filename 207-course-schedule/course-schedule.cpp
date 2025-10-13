class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses , 0);
        vector<vector<int>> adj(numCourses);

        // Build the graph 
        for(auto &pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;// No of nodes processed

            for(int next : adj[course]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }       
        }
        return count== numCourses;
    }
};