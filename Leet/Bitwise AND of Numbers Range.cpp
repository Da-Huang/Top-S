// #redo
int rangeBitwiseAnd(int m, int n) {
  int k = 0, t = m;
  while (t) {
    t >>= 1;
    ++ k;
  }
  if (k == 0) return 0;
  k = 1 << (k - 1);
  if ((n & k) == 0 || ~((k-1) | k) & n) return 0;

  int ans = 0;
  while (k) {
    if ((k & m) != (k & n)) break;
    ans |= k & m;
    k >>= 1;
  }
  return ans;
}
