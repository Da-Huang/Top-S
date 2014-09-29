int uniquePaths(int m, int n) {
  n = m + n - 2;
  m = m - 1;
  // get C(n, m)
  long long res = 1;
  for (int i = 1; i <= m; i ++) {
    int a = n - m + i;
    int b = i;
    res *= a;
    res /= b;
  }
  return res;
}

