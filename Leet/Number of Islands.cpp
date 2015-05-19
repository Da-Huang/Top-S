void __visitIsland(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
  if (grid[i][j] == '0' || visited[i][j]) return;

  const int M = grid.size();
  const int N = grid[0].size();

  visited[i][j] = true;
  if (i > 0) __visitIsland(grid, visited, i-1, j);
  if (j > 0) __visitIsland(grid, visited, i, j-1);
  if (i+1 < M) __visitIsland(grid, visited, i+1, j);
  if (j+1 < N) __visitIsland(grid, visited, i, j+1);
}

int numIslands(vector<vector<char>>& grid) {
  const int M = grid.size();
  if (M == 0) return 0;
  const int N = grid[0].size();
  if (N == 0) return 0;

  int ans = 0;
  vector<vector<bool>> visited(M, vector<bool>(N, false));
  for (int i = 0; i < M; ++ i) {
    for (int j = 0; j < N; ++ j) {
      if (visited[i][j] || grid[i][j] == '0') continue;
      ++ ans;
      __visitIsland(grid, visited, i, j);
    }
  }
  return ans;
}
