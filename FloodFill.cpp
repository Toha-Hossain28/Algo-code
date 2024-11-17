// https://leetcode.com/problems/flood-fill/

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();

    int originalColor = image[sr][sc];
    if (originalColor == color) return image;

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));


    // Start from the given cell
    q.push({ sr, sc });
    vis[sr][sc] = 1;
    image[sr][sc] = color;

    int dRow[] = { -1, 0, 1, 0 };
    int dCol[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nrow = r + dRow[i];
        int ncol = c + dCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && image[nrow][ncol] == originalColor) {
          image[nrow][ncol] = color;
          q.push({ nrow, ncol });
          vis[nrow][ncol] = 1;
        }
      }
    }
    return image;
  }
};