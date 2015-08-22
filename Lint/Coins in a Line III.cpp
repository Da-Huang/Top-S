// #redo
bool firstWillWin(vector<int> &values) {
  const int N = values.size();
  if (N == 0) return false;
  vector<vector<int>> ans(N, vector<int>(N));
  for (int i = 0; i < N; ++i) ans[i][i] = values[i];
  for (int i = N-2; i >= 0; --i) {
    for (int j = i+1; j < N; ++j) {
      ans[i][j] = max(values[i]-ans[i+1][j], values[j]-ans[i][j-1]);
    }
  }
  return ans[0][N-1] > 0;
}
