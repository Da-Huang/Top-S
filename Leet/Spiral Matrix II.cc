vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> ans(n, vector<int>(n));
  int k = 0;
  for (int r = 0; r < (n+1)/2; ++ r) {
    int i = r, j;
    for (j = r; j < n - r; ++ j) ans[i][j] = ++ k;
    j = n - r - 1;
    for (i = r + 1; i < n - r; ++ i) ans[i][j] = ++ k;
    i = n - r - 1;
    for (j = n - r - 2; j >= r; -- j) ans[i][j] = ++ k;
    j = r;
    for (i = n - r - 2; i > r; -- i) ans[i][j] = ++ k;
  }
  return ans;
}
