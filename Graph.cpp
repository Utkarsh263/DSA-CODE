// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;


// class Graph{
// public:
//     int V;
//     list<int> *l;

//     Graph(int V){
//         this->V = V;
//         l= new list<int> [V];
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     void print(){
//         for(int u=0; u<V; u++){
//             list<int> neighbors = l[u];
//             cout<< u<<":";
//             for(int v : neighbors){
//                 cout<<v<<" ";
//             }
//             cout<<endl;
//         }
//     }
// };

// int main(){
//     Graph graph(5);

//     graph.addEdge(0,1);
//     graph.addEdge(1,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,3);
//     graph.addEdge(2,4);

//     graph.print();
    
//     return 0;
// }

// #include <iostream>
// #include <list>
// #include <vector>
// using namespace std;

// class Graph{
//     int V;
//     list<int> *l;
// public:
//     Graph(int V){
//         this->V = V;
//         l = new list<int> [V];
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     void print(){
//         for(int u=0; u<V; u++){
//             list<int> neighbors = l[u];
//             cout<< u <<":";
//             for(int v : neighbors){
//                 cout<<v<<" ";
//             }
//             cout<<endl;
//         }
//     }
// };

// int main(){

//     Graph graph(5);

//     graph.addEdge(0,1);
//     graph.addEdge(1,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,4);
//     graph.addEdge(2,3);

//     graph.print();
//     return 0;
// }


// Graph Traversals


// #include <iostream>
// #include <queue>
// #include <list>
// #include <vector>
// using namespace std;

// class Graph{
//     int V;
//     list<int> *l;
// public:
//     Graph(int V){
//         this->V = V;
//         l = new list<int> [V];
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     void print(){
//         for(int u=0; u<V; u++){
//             list<int> neighbors = l[u];
//             cout<<u<<":";
//             for(int v: neighbors){
//                 cout<<v<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     void bfs(){// O(V+E)
//         queue<int> q;
//         vector<bool> vis(V , false);
//         q.push(0);
//         vis[0]= true;

//         while(q.size()>0){
//             int u= q.front();
//             q.pop();
//             cout<<u<<" ";

//             list<int> neighbors = l[u];
//             for(int v : neighbors){
//                 if(!vis[v]){
//                     vis[v]= true;
//                     q.push(v);
//                 }
//             }
//         }
//         cout<<endl;
//     }
// };


// int main(){
//     Graph graph(7);

//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,4);
//     graph.addEdge(3,4);
//     graph.addEdge(3,5);
//     graph.addEdge(4,5);
//     graph.addEdge(5,6);


//     //graph.print();
//     graph.bfs();
//     return 0;
// }


// #include <iostream>
// #include <list>
// #include <vector>
// using namespace std;

// class Graph{
// public:
//     int V;
//     list<int> *l;

//     Graph(int V){
//         this->V = V;
//         l = new list<int> [V];
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);  // u-->v
//         l[v].push_back(u); // v-->u
//     }

//     void print(){
//         for(int u=0; u<V; u++){
//             list<int> neighbors = l[u];
//             cout<< u<< "->";
//             for(int v : neighbors){
//                 cout<< v<<" ";
//             }
//             cout<<endl;
//         }
//     }

    

//     void dfsHelper(int u , vector<bool> &visited){
//         visited[u]= true;
//         cout<< u << " ";

//         list<int> neighbors = l[u];
//         for(int v : neighbors){
//             if(!visited[v]){
//                dfsHelper(v,visited); 
//             }
//         }
//     }

//     void dfs(int u){
//         vector<bool> visited(7, false);
//         dfsHelper(u, visited);
//     }



// };

// int main() {

//     Graph graph(7);

//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,4);
//     graph.addEdge(3,4);
//     graph.addEdge(3,5);
//     graph.addEdge(4,5);
//     graph.addEdge(5,6);

//     // graph.print();
    

//     graph.dfs(0);
    
//     return 0;
// }

// HasPath Problem 

// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;


// class Graph{
// public:
//     int V;
//     list<int> *l;

//     Graph(int V){
//         this->V = V;
//         l = new list<int> [V];
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         l[v].push_back(u);

//     }

//     void print(){
//         for(int u=0; u<V ; u++){
//             cout<< u <<"->";
//             list<int> neighbors = l[u];
//             for(int v :neighbors){
//                 cout<<v<<" ";
//             }cout<<endl;
//         }
//     }

//     bool pathHelper(int src, int dest, vector<bool> &visited){
//         if(src == dest){
//             return true;
//         }
//         visited[src]= true;
//         list<int> neighbors = l[src];

//         for(int v: neighbors){
//             if(!visited[v]){
//                 if(pathHelper(v, dest, visited)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool HasPath(int src, int dest){
//         vector<bool> visited(7, false);
//         return pathHelper( src,dest, visited);
//     }
// };

// int main(){

//     Graph graph(7);

//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,4);
//     graph.addEdge(3,4);
//     graph.addEdge(3,5);
//     graph.addEdge(4,5);
//     // graph.addEdge(5,6);

//     // graph.print();
//     cout<<graph.HasPath(0,6);

// }


// Disconnected Components

// #include <iostream>
// #include <list>
// #include <vector>
// #include <string>
// using namespace std;

// class Graph{
// public:
//     int V;
//     list<int> *l;

//     Graph(int V){
//         this->V = V;
//         l = new list<int> [V];
//     }

//     void addEdge(int u , int v){
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     void print(){
//         for(int u=0; u<V ; u++){
//             cout<<u<<"->";
//             list<int> neighbors = l[u];
//             for(int v: neighbors){
//                 cout<< v<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     void dfsHelper(int V, vector<bool> &visited){
//         visited[V] = true;
//         cout<< V << " ";

//         list<int> neighbors = l[V];
//         for(int v : neighbors){
//             if(!visited[v]){
//                 dfsHelper(v,visited);
//                 cout<<endl;
//             }
//         }
//     }

//     void dfs(){
//         vector<bool> visited(V, false);
//         for(int i=0; i<V; i++){
//             if(!visited[i]){
//                 dfsHelper(i, visited);
//             }
//         }
//     }
// };

// int main(){

//     Graph graph(10);

//     graph.addEdge(1,6);
//     graph.addEdge(6,4);
//     graph.addEdge(4,9);
//     graph.addEdge(4,3);
//     graph.addEdge(3,8);
//     graph.addEdge(3,7);
//     graph.addEdge(2,5);
//     graph.addEdge(2,0);
    
//     graph.dfs();
// }


// #include <iostream>
// #include <list>
// #include <vector>
// #include <queue>
// using namespace std;

// class Graph {
// public:
//     int V;
//     list<int> *l;

//     Graph(int V) {
//         this->V = V;
//         l = new list<int>[V];
//     }

//     void addEdge(int u, int v) {
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     void print() {
//         for (int u = 0; u < V; u++) {
//             cout << u << " -> ";
//             for (int v : l[u]) {
//                 cout << v << " ";
//             }
//             cout << endl;
//         }
//     }

//     // DFS -----------------------------
//     void dfsHelper(int node, vector<bool> &visited) {
//         visited[node] = true;
//         cout << node << " ";
//         for (int v : l[node]) {
//             if (!visited[v]) {
//                 dfsHelper(v, visited);
//             }
//         }
//     }

//     void dfs() {
//         vector<bool> visited(V, false);
//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 dfsHelper(i, visited);
//                 cout << endl;
//             }
//         }
//     }

//     // BFS -----------------------------
//     void bfs() {
//         vector<bool> visited(V, false);
//         for (int start = 0; start < V; start++) {
//             if (!visited[start]) {
//                 queue<int> q;
//                 q.push(start);
//                 visited[start] = true;

//                 while (!q.empty()) {
//                     int node = q.front();
//                     q.pop();
//                     cout << node << " ";

//                     for (int v : l[node]) {
//                         if (!visited[v]) {
//                             q.push(v);
//                             visited[v] = true;
//                         }
//                     }
//                 }
//                 cout << endl; // end of one connected component
//             }
//         }
//     }
// };

// int main() {
//     Graph graph(10);

//     graph.addEdge(1, 6);
//     graph.addEdge(6, 4);
//     graph.addEdge(4, 9);
//     graph.addEdge(4, 3);
//     graph.addEdge(3, 8);
//     graph.addEdge(3, 7);
//     graph.addEdge(2, 5);
//     graph.addEdge(2, 0);
//     graph.addEdge(1, 2);


//     cout << "DFS Traversal:\n";
//     graph.dfs();

//     cout << "\nBFS Traversal:\n";
//     graph.bfs();
//}

// Cycles in a graph 

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <list>
// #include <string>
// using namespace std;

// class Graph{
// public:
//     int V;
//     list<int> *l;

//     Graph(int V){
//         this-> V = V;
//         l = new list<int> [V];
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     void print(){
//         for(int u=0; u<V ; u++){
//             cout<< u<< "->";
//             list<int> neighbors = l[u];
//             for(int v : neighbors){
//                 cout<<v<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     bool undireCycleHelper(int src, int par, vector<bool> &visited){
//         visited[src]= true;

//         list<int> neighbors = l[src];
//         for(int v : neighbors){
//             if(!visited[v]){
//                 if(undireCycleHelper(v, src, visited)){
//                     return true;
//                 }
//             }else{
//                 if(v != par){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool isCycleUndir(){
//         vector<bool> visited(V, false);
//         return undireCycleHelper(0,-1, visited);
//     }
// };


// int main(){
//     int V=5;
//     Graph graph(V);

//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(0,3);

//     graph.addEdge(1,2);

//     graph.addEdge(3,4);

//     cout<< graph.isCycleUndir();

// }


// #include <iostream>
// #include <vector>
// #include <list>
// #include <queue>
// #include <string>
// using namespace std;

// class Graph{
//     int V;
//     list<int> *l;
//     bool isUndir;
// public:
//     Graph(int V, bool isUndir = true){
//         this->V = V;
//         l = new list<int> [V];
//         this->isUndir = isUndir;
//     }

//     void addEdge(int u , int v){
//         l[u].push_back(v);
//         if(isUndir){
//             l[v].push_back(u);
//         }
//     }

//     void print(){
//         for(int u=0; u<V; u++){
//             cout<< u<<"->";
//             list<int> neighbors = l[u];
//             for(int v : neighbors){
//                 cout<< v<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     bool helperCycleDir(int src, vector<bool> &vis, vector<bool> &recPath){
//         vis[src] = true;
//         recPath[src] = true; 
//         list<int> neighbors = l[src];

//         for(int v : neighbors){
//             if(!vis[v]){
//                 if(helperCycleDir(v, vis, recPath)){
//                     return true;
//                 }
//             }else{
//                 if(recPath[v]){
//                     return true;
//                 }
//             }
//         }
//         recPath[src] = false;
//         return false;
//     }

//     bool isCycleDir(){
//         vector<bool>vis(V, false);
//         vector<bool>recPath(V, false);

//         for(int i=0; i<V ; i++){
//             if(!vis[i]){
//                 if(helperCycleDir(i, vis, recPath)){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

// int main(){

//     Graph graph(4, false);
//     graph.addEdge(1,0);
//     graph.addEdge(0,2);
//     graph.addEdge(2,3);
//     graph.addEdge(3,0);

//     cout<<graph.isCycleDir();

//     return 0;
// }


// Bipartite graph 

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <list>
// using namespace std;

// class Graph{
// public:
//     int V;
//     list<int> *l;
//     bool isUndir;

//     Graph(int V, bool isUndir = true){
//         this-> V = V;
//         l = new list<int> [V];
//         this->isUndir = isUndir;
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         if(isUndir){
//             l[v].push_back(u);
//         }
//     }

//     void print(){
//         for(int u=0; u<V; u++){
//             cout<< u<<"->";
//             list<int> neighbors = l[u];
//             for(int v : neighbors){
//                 cout<< v << " ";
//             }
//             cout<<endl;
//         }
//     }

//     bool isbipartite(){
//         queue<int> q;
//         vector<bool> visited (V , false);
//         vector<int> color(V, -1);

//         q.push(0);
//         visited[0]= true;
//         color[0]=0;

//         while(q.size()>0){
//             int curr = q.front();
//             q.pop();

//             list<int> neighbors = l[curr];
//             for(int v : neighbors){
//                 if(visited[v]){
//                     if(color[curr]== color[v]){
//                         return false;
//                     }
//                 }else{
//                     visited[v]= true;
//                     color[v] = !color[curr];
//                     q.push(v);
//                 }
//             }
//         }

//         return true;
//     }
// };


// int main(){

//     Graph graph(4);

//     // graph.addEdge(0,1);
//     // graph.addEdge(0,2);
//     // graph.addEdge(0,3);
//     // graph.addEdge(1,2);
//     // graph.addEdge(3,4);

//     // graph.addEdge(0,1);
//     // graph.addEdge(0,2);
//     // graph.addEdge(1,3);
//     // graph.addEdge(2,3);

//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,3);
//     graph.addEdge(0,3);
    

//     cout<<graph.isbipartite();

//     return 0;
// }



// All paths Problem 

// #include <iostream>
// #include <queue>
// #include <stack>
// #include <list>
// #include <vector>
// #include <string>
// using namespace std;

// class Graph{
// public:
//     int V;
//     list<int> *l;
//     bool isUndir;

//     Graph(int V, bool isUndir= true){
//         this-> V = V;
//         l = new list<int> [V];
//         this->isUndir = isUndir;
//     }

//     void addEdge(int u , int v){
//         l[u].push_back(v);
//         if(isUndir){
//             l[v].push_back(u);
//         }
//     }

//     void print(){
//         for(int u=0; u<V; u++){
//             cout<< u<< "->";
//             list<int> neighbors = l[u];
//             for(int v : neighbors){
//                 cout<< v<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     void pathHelper(int src, int dest, vector<bool> &visited , string &path){
//         if(src== dest){
//             cout<<path<<dest<<endl;
//             return ;
//         }

//         visited[src]= true;
//         path += to_string(src);
//         list<int> neighbors = l[src];


//         for(int v : neighbors){
//             if(!visited[v]){// Prevent Cycle in a Graph
//                 pathHelper(v, dest, visited, path);
//             }
//         }

//         path = path.substr(0, path.size()-1);
//         visited[src] = false; // Create multiple Paths
//     }

//     void printAllPaths(int src, int dest){
//         vector<bool>visited(V, false);
//         string path = "";
//         pathHelper(src, dest, visited, path);
//     }
// };

// int main(){
//     Graph graph(6, false);
//     graph.addEdge(0,3);
//     graph.addEdge(2,3);
//     graph.addEdge(3,1);
//     graph.addEdge(4,0);
//     graph.addEdge(4,1);
//     graph.addEdge(5,0);
//     graph.addEdge(5,2);

//     graph.printAllPaths(5,1);
//     return 0;
// }


// Topological Sorting 

// #include <iostream>
// #include <queue>
// #include <stack>
// #include <list>
// #include <vector>
// #include <string>
// using namespace std;


// class Graph{
// public:
//     int V;
//     list<int> *l;
//     bool isUndir;

//     Graph(int V , bool isUndir = true){
//         this-> V = V;
//         l = new list<int> [V];
//         this->isUndir = isUndir;
//     }
    
//     void addEdge(int u , int v){
//         l[u].push_back(v);
//         if(isUndir){
//             l[v].push_back(u);
//         }
//     }

//     void topoHelper(int src, vector<bool>&visited, stack<int> &s){
//         visited[src] = true;

//         list<int> neighbors = l[src];
//         for(int v: neighbors){
//             if(!visited[v]){
//                 topoHelper(v, visited, s);
//             }
//         }

//         s.push(src);
//     } 

//     void topologicalSort(){
//         vector<bool> visited(V, false);
//         stack<int> s;

//         for(int i=0; i<V ; i++){
//             if(!visited[i]){
//                 topoHelper(i,visited, s);
//             }
//         }

//         // print topological order
//         while(!s.empty()){
//             cout<<s.top()<<endl;
//             s.pop();
//         }
//     }
// };

// int main(){
//     Graph graph(6, false);

//     graph.addEdge(2,3);
//     graph.addEdge(3,1);

//     graph.addEdge(4,0);
//     graph.addEdge(4,1);

//     graph.addEdge(5,0);
//     graph.addEdge(5,2);

//     graph.topologicalSort();
//     return 0;
// }


// Kahn's Algorithm  

// #include <iostream>
// #include <list>
// #include <stack>
// #include <queue>
// #include <vector>
// using namespace std;

// class Graph{
// public:
//     int V;
//     list<int> *l;
//     bool isUndir;

//     Graph(int V, bool isUndir = true){
//         this->V =V;
//         l = new list<int> [V];
//         this->isUndir = isUndir;
//     }

//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         if(isUndir){
//             l[v]. push_back(u);
//         }
//     }

//     void calcIndegree(vector<int> &indegree){
//         for(int u=0; u<V; u++){
//             list<int> neighbors = l[u];
//             for(int v : neighbors){
//                 indegree[v]++;
//             }
//         }
//     }

//     void topoSort2(){// kahn's algo
//         vector<int>indeg(V, 0);
//         calcIndegree(indeg);
//         queue<int> q;
//         // push nodes having indegree 0
//         for(int i=0; i<V; i++){
//             if(!indeg[i]){
//                 q.push(i);
//             }
//         }

//         // final bfs
//         while(!q.empty()){
//             int curr= q.front();
//             q.pop();
//             cout<<curr<<" ";

//             list<int> neighbors = l[curr];
//             for(int v: neighbors){
//                 indeg[v]--;
//                 if(!indeg[v]){// indeg become zero so no pending dependency
//                     q.push(v);
//                 }
//             }
//         }

//         cout<<endl;
//     }
// };

// int main(){

//     Graph graph(6, false);

//     graph.addEdge(2,3);
//     graph.addEdge(3,1);

//     graph.addEdge(4,0);
//     graph.addEdge(4,1);

//     graph.addEdge(5,0);
//     graph.addEdge(5,2);

//     graph.topoSort2();
//     return 0;
// }

// Dijkstra Algo

// #include <iostream>
// #include <stack>
// #include <queue>
// #include <vector>
// #include <list>
// using namespace std;

// class Edge{
// public:
//     int v;
//     int wt;

//     Edge(int v, int wt){
//         this->v = v;
//         this->wt = wt;
//     }
// };

// void dijkstra(int src,vector<vector<Edge>> &graph, int V){
//     priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // min heap
//     vector<int> dist(V, INT16_MAX);

//     pq.push(make_pair(0, src));
//     dist[src]=0;

//     while(!pq.empty()){
//         int u = pq.top().second;
//         pq.pop();

//         vector<Edge> edges = graph[u];
//         for(Edge e : edges){
//             if(dist[e.v] > dist[u] +e.wt){
//                 dist[e.v]= dist[u]+ e.wt;
//                 pq.push(make_pair(dist[e.v],e.v));
//             }
//         }
//     }

//     for (int d: dist){
//         cout<<d<<" ";
//     }
//     cout<<endl;
// }

// int main(){

//     int V=6;
//     vector<vector<Edge>> graph(V);

//     graph[0].push_back(Edge(1,2));
//     graph[0].push_back(Edge(2,4));

//     graph[1].push_back(Edge(2,1));
//     graph[1].push_back(Edge(3,7));

//     graph[2].push_back(Edge(4,3));

//     graph[3].push_back(Edge(5,1));

//     graph[4].push_back(Edge(3,2));
//     graph[4].push_back(Edge(2,5));
    
//     dijkstra(0, graph,V);

// }

// Bellman Ford Algo

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <string>
// using namespace std;

// class Edge{
// public:
//     int v;
//     int wt;

//     Edge(int v, int wt){
//         this->v = v;
//         this->wt = wt;
//     }
// };

// void bellmanFord(vector<vector<Edge>> graph, int V, int src){// O(V.E)
//     vector<int>dist(V,INT16_MAX);
//     dist[src]=0;

//     for(int i=0; i<V; i++){
//         for(int u=0; u<V; u++){
//             for(Edge e : graph[u]){
//                 if(dist[e.v] > dist[u]+e.wt){
//                     dist[e.v] = dist[u] + e.wt;
//                 }
//             }
//         }
//     }

//     for(int i=0; i<dist.size(); i++){
//         cout<< dist[i]<< " ";
//     }
//     cout<<endl;
// }


// int main(){
//     int V=5;
//     vector<vector<Edge>> graph(V);

//     graph[0].push_back(Edge(1,2));
//     graph[0].push_back(Edge(2,4));

//     graph[1].push_back(Edge(2,-4));

//     graph[2].push_back(Edge(3,2));

//     graph[3].push_back(Edge(4,4));

//     graph[4].push_back(Edge(1,-1));

//     bellmanFord(graph,V,4);
// }


// Prims Algo

// #include <iostream>
// #include <string>
// #include <vector>
// #include <list>
// #include <queue>
// using namespace std;

// class Graph{
//     int V;
//     list<pair<int, int>> *l;
//     bool isUndir;

// public:
//     Graph(int V, bool isUndir = true){
//         this->V = V;
//         l = new list<pair<int, int>> [V];
//         this->isUndir = isUndir;
//     }

//     void addEdge(int u, int v, int wt){
//         l[u].push_back(make_pair(v, wt));
//         if(isUndir){
//             l[v].push_back(make_pair(u, wt));
//         }
//     }

//     void primsAlgo(int src){
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

//         pq.push(make_pair(0, src));
//         vector<bool> mst(V, false);
//         int ans=0;

//         while(!pq.empty()){
//             int u = pq.top().second;
//             int wt = pq.top().first;
//             pq.pop();

//             if(!mst[u]){
//                 mst[u]= true;
//                 ans= ans+wt;
//                 list<pair<int, int>> neighbors = l[u];
//                 for(pair<int, int> n: neighbors){
//                     int v= n.first;
//                     int currWt = n.second;
//                     pq.push(make_pair(currWt, v));
//                 }

                
//             }
//         }

//        cout<<ans<<endl;
//     }
// };


// int main(){

//     Graph graph(4);

//     graph.addEdge(0,1,10);
//     graph.addEdge(0,2,15);
//     graph.addEdge(0,3,30);

//     graph.addEdge(1,3,40);
//     graph.addEdge(2,3,50);

//     graph.primsAlgo(0);
// }


// Disjoint Set 

// #include <iostream>
// #include <vector>
// using namespace std;

// class DisjointSet{
// public:
//     int n;
//     vector<int> par;
//     vector<int> rank;

//     DisjointSet(int n){
//         this->n = n;
//         for(int i=0; i<n; i++){
//             par.push_back(i);
//             rank.push_back(0);
//         }
//     }

//     int find(int x){
//         if(par[x]==x){
//             return x;
//         }

//         return par[x]=find(par[x]);
//     }

//     void UnionbyRank(int a, int b){
//         int parA = find(a);
//         int parB = find(b);

//         if(rank[parA]==rank[parB]){
//             par[parB] = parA;
//             rank[parA]++;
//         }else if(rank[parA] > rank[parB]){
//             par[parB] = parA;
//         }else{
//             par[parA] = parB;
//         }
//     }

//     void printInfo(){
//         for(int i=0; i<n; i++){
//             cout<<i<<":"<<par[i]<<","<<rank[i]<<endl;
//         }
//     }
// };

// int main(){
//     DisjointSet dj(6);
//     dj.UnionbyRank(0,2);
//     cout<<dj.find(2)<<endl;
//     dj.UnionbyRank(1,3);
//     dj.UnionbyRank(2,5);
//     dj.UnionbyRank(0,3);
//     cout<<dj.find(2)<<endl;
//     dj.UnionbyRank(0,4);
//     cout<<"Printing Information"<<endl;
//     dj.printInfo();

// }


// Krushkal Algo

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class Edge{
public:
    int u; 
    int v;
    int wt;
    Edge(int u,int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph{
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int V){
        this->V = V;

        for(int i=0; i<V; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }

        return par[x]= find(par[x]);
    }

    void unionByRank(int u , int v){
        int parU= find(u);
        int parV= find(v);

        if(rank[parU]== rank[parV]){
            par[parV]= parU;
            rank[parU]++;
        }else if(rank[parU] > rank[parV]){
            par[parV]= parU;
        }else{
            par[parU]= parV;
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u,v,wt));
    }

    void krushkal(){// O(ElogE)
        sort(edges.begin(), edges.end(),[](Edge &a , Edge &b){return a.wt < b.wt;});
        int minCost =0;
        int count = 0;


        for(int i=0; i<edges.size() && count<V-1; i++){


            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV){
                unionByRank(parU, parV);
                minCost += e.wt;
            }
        }

        cout<<minCost<<endl;
    }

};

int main(){
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);

    graph.krushkal();
    return 0;
}


