int minPathSum(vector<vector<int> > &grid) {
  const int M = grid.size();
  if ( M == 0 ) return 0;
  const int N = grid[0].size();
  if ( N == 0 ) return 0;
  int res[M][N];
  res[0][0] = grid[0][0];
  for (int i = 1; i < M; i ++) res[i][0] = res[i - 1][0] + grid[i][0];
  for (int j = 1; j < N; j ++) res[0][j] = res[0][j - 1] + grid[0][j];
  for (int i = 1; i < M; i ++) {
    for (int j = 1; j < N; j ++) {
      res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
    }
  }
  return res[M - 1][N - 1];
}
