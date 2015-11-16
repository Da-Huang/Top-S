int minPathSum(vector<vector<int>>& grid) {
  const int M = grid.size();
  if (M == 0) return 0;
  const int N = grid[0].size();
  if (N == 0) return 0;

  int sum[2][N];
  sum[0][0] = grid[0][0];
  for (int j = 1; j < N; ++ j) sum[0][j] = sum[0][j-1] + grid[0][j];
  for (int i = 1; i < M; ++ i) {
    sum[i&1][0] = sum[(i-1)&1][0] + grid[i][0];
    for (int j = 1; j < N; ++ j) {
      sum[i&1][j] = min(sum[(i-1)&1][j], sum[i&1][j-1]) + grid[i][j];
    }
  }
  return sum[(M-1)&1][N-1];
}
