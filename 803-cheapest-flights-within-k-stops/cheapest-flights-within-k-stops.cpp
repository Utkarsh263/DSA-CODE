class Solution {
public:
    class Info{
    public:
        int u; 
        int cost; 
        int stops;

        Info(int u, int cost, int stops){
            this->u =u;
            this->cost = cost;
            this->stops= stops;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int V = n;
      queue<Info> q;
      vector<int> dist(V, INT_MAX);

      dist[src]=0;
      q.push(Info(src, 0, -1));

      while(!q.empty()){
        Info curr = q.front();
        q.pop();

        for(int i=0; i<flights.size(); i++){
            if(flights[i][0]==curr.u){
                int v = flights[i][1];
                int price = flights[i][2];

                if(dist[v] > curr.cost+ price && curr.stops+1<=k){
                    dist[v] = curr.cost+ price;
                    q.push(Info(v, dist[v], curr.stops+1));
                }
            }
        }
      }
      if(dist[dst]==INT_MAX){
        return -1;
      }

      return dist[dst];
    }
};


// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         // Step 1: Build adjacency list
//         vector<pair<int,int>> adj[n];
//         for (auto& f : flights) {
//             adj[f[0]].push_back({f[1], f[2]}); // from -> (to, price)
//         }

//         // Step 2: Min-heap: (cost so far, current city, stops used)
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//         pq.push({0, src, 0}); // cost=0, start=src, stops=0

//         // Step 3: Track best [city][stops] cost
//         vector<int> dist(n, INT_MAX);
//         dist[src] = 0;

//         while (!pq.empty()) {
//             auto t = pq.top(); pq.pop();
//             int cost = t[0], node = t[1], stops = t[2];

//             if (node == dst) return cost; // reached destination

//             if (stops > k) continue; // exceeded stop limit

//             for (auto& [next, price] : adj[node]) {
//                 int newCost = cost + price;
//                 // if this path is cheaper, explore it
//                 if (newCost < dist[next] || stops < k) {
//                     dist[next] = newCost;
//                     pq.push({newCost, next, stops + 1});
//                 }
//             }
//         }
//         return -1;
//     }
// };
