// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/0

// User Function Template
class Solution {
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex src.
  vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(adj.size(), INT_MAX);
    dist[src] = 0;
    pq.push({ 0,src });

    while (!pq.empty()) {
      int node = pq.top().second;
      int wt = pq.top().first;
      pq.pop();

      for (auto it : adj[node]) {
        int v = it.first;
        int w = it.second;
        if (wt + w < dist[v]) {
          dist[v] = wt + w;
          pq.push({ wt + w,v });
        }
      }
    }
    return dist;
  }
};