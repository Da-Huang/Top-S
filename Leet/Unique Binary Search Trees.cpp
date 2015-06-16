int numTrees(int n) {
  int ans[n+1];
  ans[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    ans[i] = 0;
    for (int j = 0; j < i; ++ j) {
      ans[i] += ans[j] * ans[i-1-j];
    }
  }
  return ans[n];
}
