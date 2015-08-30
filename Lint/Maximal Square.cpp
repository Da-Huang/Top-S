// #redo
int maxSquare(vector<vector<int> > &matrix) {
  const int M = matrix.size();
  if (M == 0) return 0;
  const int N = matrix[0].size();
  if (N == 0) return 0;
  int h[N];
  memset(h, 0, sizeof(h));
  int ans_max = 0;
  int ans[2][N];
  for (int i = 0; i < M; ++i) {
    int r = 0;
    for (int j = 0; j < N; ++j) {
      if (matrix[i][j]) {
        ++h[j];
        ++r;
        ans[i & 1][j] = i == 0 || j == 0 ? 1 : ans[(i - 1) & 1][j - 1] + 1;
        ans[i & 1][j] = min({ans[i & 1][j], h[j], r});
        ans_max = max(ans_max, ans[i & 1][j]);

      } else {
        h[j] = 0;
        r = 0;
        ans[i & 1][j] = 0;
      }
    }
  }
  return ans_max * ans_max;
}
