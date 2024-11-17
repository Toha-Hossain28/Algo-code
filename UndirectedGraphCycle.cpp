// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0

class Solution {
private:
  bool detectCycle(int src, vector<vector<int>>& adj, int vis[]) {
    queue<pair<int, int>> q;
    q.push({ src, -1 });
    vis[src] = 1;

    while (!q.empty()) {
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();

      for (auto it : adj[node]) {
        if (!vis[it]) {
          vis[it] = 1;
          q.push({ it, node });
        }
        else if (it != parent) {
          return true;
        }
      }
    }
    return false;
  }
public:
  // Function to detect cycle in an undirected graph.
  bool isCycle(vector<vector<int>>& adj) {
    // Code here
    int vis[adj.size()] = { 0 };
    for (int i = 0; i < adj.size(); i++) {
      if (!vis[i]) {
        if (detectCycle(i, adj, vis))
          return true;
      }
    }
    return false;

  }
};