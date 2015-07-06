// #redo
double myPow(double x, int n) {
  double ans = 1;
  double cache = x;
  int m = n < 0 ? -(n + 1) : n;

  for (int i = 0; i < 31; ++ i) {
    if (m && (1 << i)) ans *= cache;
    cache *= cache;
  }
  return n < 0 ? 1 / x / ans : ans;
}
