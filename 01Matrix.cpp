// https://leetcode.com/problems/01-matrix/

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
    vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), 0));

    int n = mat.size();
    int m = mat[0].size();

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0;i < mat.size();i++) {
      for (int j = 0;j < mat[0].size();j++) {
        if (mat[i][j] == 0) {
          vis[i][j] = 1;
          q.push({ {i,j},0 });
        }
      }
    }

    int dRow[] = { -1,0,1,0 };
    int dCol[] = { 0,1,0,-1 };

    while (!q.empty()) {
      int r = q.front().first.first;
      int c = q.front().first.second;
      int step = q.front().second;

      q.pop();
      for (int i = 0;i < 4;i++) {
        int nRow = r + dRow[i];
        int nCol = c + dCol[i];

        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol]) {
          if (mat[nRow][nCol] == 1) {
            q.push({ {nRow,nCol},step + 1 });
            vis[nRow][nCol] = 1;
            dist[nRow][nCol] = step + 1;
          }
        }
      }
    }
    return dist;
  }
};