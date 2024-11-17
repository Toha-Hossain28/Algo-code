// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/0

class Solution
{
public:
  //Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);

    pq.push({ 0,0 }); //w,v
    int sum = 0;
    while (!pq.empty()) {
      int w = pq.top().first;
      int v = pq.top().second;
      pq.pop();

      if (vis[v] == 1) continue;

      vis[v] = 1;
      sum += w;

      for (auto it : adj[v]) {
        int adjNode = it[0];
        int wt = it[1];

        if (!vis[adjNode]) {
          pq.push({ wt,adjNode });
        }
      }
    }

    return sum;
  }
};