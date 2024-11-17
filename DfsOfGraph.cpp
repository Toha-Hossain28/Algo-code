// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/0

class Solution {
private:
  void dfs(int node, vector<vector<int>>& adj, int visited[], vector<int>& dfsList) {
    visited[node] = 1;
    dfsList.push_back(node);
    for (auto it : adj[node]) {
      if (!visited[it]) {
        dfs(it, adj, visited, dfsList);
      }
    }
  }

public:
  // Function to return a list containing the DFS traversal of the graph.
  vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    // Code here
    int visited[adj.size()] = { 0 };
    int start = 0;
    vector<int> dfsList;
    dfs(start, adj, visited, dfsList);
    return dfsList;
  }
};