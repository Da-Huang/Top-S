// #redo
int numSquares(int n) {
  int ans[n + 1];
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n / i; ++i) {
    ans[i * i] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    if (ans[i] == 0) {
      int val = i;
      for (int j = 1; j <= i / j; ++j) {
        val = min(val, 1 + ans[i - j * j]);
      }
      ans[i] = val;
    }
  }
  return ans[n];
}
