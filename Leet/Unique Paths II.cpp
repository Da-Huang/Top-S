int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
  const int M = obstacleGrid.size();
  if ( M == 0 ) return 0;
  const int N = obstacleGrid[0].size();
  if ( N == 0 ) return 0;
  int res[M][N];
  res[0][0] = obstacleGrid[0][0] ? 0 : 1;
  for (int i = 1; i < M; i ++) res[i][0] = obstacleGrid[i][0] ? 0 : res[i - 1][0];
  for (int j = 1; j < N; j ++) res[0][j] = obstacleGrid[0][j] ? 0 : res[0][j - 1];
  for (int i = 1; i < M; i ++) {
    for (int j = 1; j < N; j ++) {
      res[i][j] = obstacleGrid[i][j] ? 0 : res[i - 1][j] + res[i][j - 1];
    }
  }
  return res[M - 1][N - 1];
}
