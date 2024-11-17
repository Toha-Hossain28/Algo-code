// https://leetcode.com/problems/number-of-provinces/

class Solution {
private:
  void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    for (auto it : adj[node]) {
      if (!visited[it]) {
        dfs(it, adj, visited);
      }
    }
  }
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    vector<vector<int>> adj(isConnected.size());
    for (int i = 0;i < isConnected.size();i++) {
      for (int j = 0;j < isConnected.size();j++) {
        if (i != j && isConnected[i][j] == 1) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    // Initialize visited vector
    vector<int> visited(isConnected.size(), 0);
    int count = 0;

    // Perform DFS for each unvisited node
    for (int i = 0; i < isConnected.size(); i++) {
      if (!visited[i]) {
        count++;
        dfs(i, adj, visited);
      }
    }
    return count;
  }
};