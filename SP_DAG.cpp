// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0
// topo sort

// User function Template for C++
class Solution {
private:
  void topo(int node, int vis[], stack<int>& s, vector<pair<int, int>> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      int v = it.first;
      if (!vis[v]) {
        topo(v, vis, s, adj);
      }
    }
    s.push(node);
  }

public:
  vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // Create adjacency list with weights
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < E; i++) {
      int s = edges[i][0];
      int d = edges[i][1];
      int wt = edges[i][2];
      adj[s].push_back({ d, wt });
    }

    // Topological sort using DFS
    int vis[V] = { 0 };
    stack<int> s;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        topo(i, vis, s, adj);
      }
    }

    // Distance vector initialization
    vector<int> dist(V, 1e9);
    dist[0] = 0;  // Assuming the source node is 0

    // Process nodes in topological order
    while (!s.empty()) {
      int node = s.top();
      s.pop();
      if (dist[node] != 1e9) {  // Ensure that node is reachable
        for (auto it : adj[node]) {
          int v = it.first;
          int wt = it.second;
          if (dist[node] + wt < dist[v]) {
            dist[v] = dist[node] + wt;
          }
        }
      }
    }

    // Replace unreachable distances with -1
    for (int i = 0; i < V; i++) {
      if (dist[i] == 1e9) {
        dist[i] = -1;
      }
    }

    return dist;
  }
};