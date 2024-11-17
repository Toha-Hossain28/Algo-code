// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Initialize the queue with all rotten oranges and mark them as visited
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({ {i, j}, 0 });
          visited[i][j] = 1;
        }
      }
    }

    int time = 0;
    int dRow[] = { -1, 0, 1, 0 };
    int dCol[] = { 0, 1, 0, -1 };

    // BFS to process each level of rotting
    while (!q.empty()) {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int t = q.front().second;
      time = max(time, t);
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nrow = row + dRow[i];
        int ncol = col + dCol[i];

        // Check for valid unvisited fresh orange
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
          q.push({ {nrow, ncol}, t + 1 });
          visited[nrow][ncol] = 1; // Mark as visited (now rotten)
        }
      }
    }

    // Check if any fresh orange is left unvisited
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          return -1; // There is at least one unreachable fresh orange
        }
      }
    }

    return time;
  }
};