// #redo
long long kthPrimeNumber(int k) {
  if (k == 1) return 3;
  if (k == 2) return 5;
  if (k == 3) return 7;
  long long ans[k];
  ans[0] = 3;
  ans[1] = 5;
  ans[2] = 7;
  int i3 = 0, i5 = 1, i7 = 2;
  for (int j = 3; j < k; ++j) {
    while (ans[i3] <= ans[j - 1] / 3) ++i3;
    while (ans[i5] <= ans[j - 1] / 5) ++i5;
    while (ans[i7] <= ans[j - 1] / 7) ++i7;
    long long val = LLONG_MAX;
    if (ans[i3] <= val / 3) val = ans[i3] * 3;
    if (ans[i5] <= val / 5) val = ans[i5] * 5;
    if (ans[i7] <= val / 7) val = ans[i7] * 7;
    ans[j] = val;
  }
  return ans[k - 1];
}
