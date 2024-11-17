// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/0

class Solution {
public:
  // Function to return the adjacency list for each vertex.
  vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    // Code here
    vector<vector<int>> adjList(V);
    for (int i = 0;i < edges.size();i++) {
      int s = edges[i].first;
      int d = edges[i].second;
      adjList[s].push_back(d);
      adjList[d].push_back(s);
    }
    return adjList;
  }
};