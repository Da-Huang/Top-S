int uniquePaths(int m, int n) {
  long long ans = 1;
  for (int i = 1; i <= m - 1; ++ i) {
    ans *= n + i - 1;
    ans /= i;
  }
  return ans;
}

// #version2
int uniquePaths(int m, int n) {
  if (m == 0 || n == 0) return 0;
  int ans[2][n];
  for (int j = 0; j < n; ++ j) ans[0][j] = 1;

  for (int i = 1; i < m; ++ i) {
    ans[i&1][0] = 1;
    for (int j = 1; j < n; ++ j) {
      ans[i&1][j] = ans[i&1][j-1] + ans[(i-1)&1][j];
    }
  }
  return ans[(m-1)&1][n-1];
}
