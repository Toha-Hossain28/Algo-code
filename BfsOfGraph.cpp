// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/0

class Solution {
public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(vector<vector<int>>& adj) {
    // Code here
    int visited[adj.size()] = { 0 };
    visited[0] = 1;
    queue<int> Q;
    Q.push(0);
    vector<int> bfs;
    while (!Q.empty()) {
      int node = Q.front();
      Q.pop();
      bfs.push_back(node);

      for (auto it : adj[node]) {
        if (!visited[it]) {
          visited[it] = 1;
          Q.push(it);
        }
      }
    }
    return bfs;

  }
};