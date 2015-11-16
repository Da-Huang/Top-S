int reverse(int x) {
  bool isNegative = x < 0;
  if (x > 0) x = -x;
  int ans = 0;
  while (x) {
    int p = x % 10;
    if (ans < (INT_MIN - p) / 10) return 0;
    ans = ans * 10 + p;
    x /= 10;
  }
  return isNegative ? ans : ans == INT_MIN ? 0 : -ans;
}
