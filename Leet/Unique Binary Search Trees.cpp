int numTrees(int n) {
  int res[n + 1];
  res[0] = 1;
  for (int i = 1; i <= n; i ++) {
    res[i] = 0;
    for (int j = 0; j < i; j ++) {
      res[i] += res[j] * res[i - j - 1];
    }
  }
  return res[n];
}

