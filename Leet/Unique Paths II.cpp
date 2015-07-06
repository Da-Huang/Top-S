// #redo
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  const int M = obstacleGrid.size();
  if (M == 0) return 0;
  const int N = obstacleGrid[0].size();
  if (N == 0) return 0;

  int ans[M][N];
  ans[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
  for (int j = 1; j < N; ++ j) ans[0][j] = obstacleGrid[0][j] == 1 ? 0 : ans[0][j-1];
  for (int i = 1; i < M; ++ i) {
    ans[i][0] = obstacleGrid[i][0] == 1 ? 0 : ans[i-1][0];
    for (int j = 1; j < N; ++ j) {
      ans[i][j] = obstacleGrid[i][j] == 1 ? 0 : ans[i-1][j] + ans[i][j-1];
    }
  }
  return ans[M-1][N-1];
}
