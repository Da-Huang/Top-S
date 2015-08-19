int nthUglyNumber(int n) {
  if (n <= 0) return 0;
  int ans[n];
  ans[0] = 1;
  int i2 = 0, i3 = 0, i5 = 0;
  for (int k = 1; k < n; ++k) {
    while (ans[i2] <= ans[k-1] / 2) ++i2;
    while (ans[i3] <= ans[k-1] / 3) ++i3;
    while (ans[i5] <= ans[k-1] / 5) ++i5;
    ans[k] = min({ans[i2] * 2, ans[i3] * 3, ans[i5] * 5});
  }
  return ans[n-1];
}
