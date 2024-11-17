// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/0
// Dijkstra

class Solution {
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
      adj[it[0]].push_back({ it[1], it[2] });
      adj[it[1]].push_back({ it[0], it[2] });
    }
    // Create a priority queue for storing the nodes along with distances 
    // in the form of a pair { dist, node }.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Create a dist array for storing the updated distances and a parent array
    //for storing the nodes from where the current nodes represented by indices of
    // the parent array came from.
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++)
      parent[i] = i;

    dist[1] = 0;

    // Push the source node to the queue.
    pq.push({ 0, 1 });
    while (!pq.empty())
    {
      // Topmost element of the priority queue is with minimum distance value.
      auto it = pq.top();
      pq.pop();
      int node = it.second;
      int dis = it.first;

      // Iterate through the adjacent nodes of the current popped node.
      for (auto it : adj[node])
      {
        int adjNode = it.first;
        int edW = it.second;

        // Check if the previously stored distance value is 
        // greater than the current computed value or not, 
        if (dis + edW < dist[adjNode])
        {
          dist[adjNode] = dis + edW;
          pq.push({ dis + edW, adjNode });

          parent[adjNode] = node;
        }
      }
    }

    if (dist[n] == 1e9)
      return { -1 };

    vector<int> path;
    int node = n;

    while (parent[node] != node)
    {
      path.push_back(node);
      node = parent[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());
    path.insert(path.begin(), dist[n]);
    return path;

  }
};