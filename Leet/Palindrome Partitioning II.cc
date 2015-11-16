// #redo
int minCut(string s) {
  const int N = s.size();
  if (N <= 1) return 0;
  vector<vector<bool>> isPalin(N, vector<bool>(N));
  isPalin[N-1][N-1] = true;
  for (int i = N - 2; i >= 0; -- i) {
    isPalin[i][i] = true;
    isPalin[i][i+1] = s[i] == s[i+1];
    for (int j = i + 2; j < N; ++ j) {
      isPalin[i][j] = isPalin[i+1][j-1] && s[i] == s[j];
    }
  }
  int ans[N];
  ans[0] = 0;
  for (int i = 1; i < N; ++ i) {
    if (isPalin[0][i]) ans[i] = 0;
    else {
      ans[i] = i;
      for (int j = 1; j <= i; ++ j) {
        if (isPalin[j][i]) ans[i] = min(ans[i], ans[j - 1] + 1);
      }
    }
  }
  return ans[N - 1];
}
