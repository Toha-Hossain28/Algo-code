// https://www.geeksforgeeks.org/problems/topological-sort/0

class Solution {
private:
  void dfs(int node, int vis[], stack<int>& s, vector<vector<int>>& adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it]) {
        dfs(it, vis, s, adj);
      }
    }
    s.push(node);
  }
public:
  // Function to return list containing vertices in Topological order.
  vector<int> topologicalSort(vector<vector<int>>& adj) {
    // Your code here
    int vis[adj.size()] = { 0 };
    stack<int> s;
    for (int i = 0;i < adj.size();i++) {
      if (!vis[i]) {
        dfs(i, vis, s, adj);
      }
    }

    vector<int> v;
    while (!s.empty()) {
      v.push_back(s.top());
      s.pop();
    }
    return v;
  }
};