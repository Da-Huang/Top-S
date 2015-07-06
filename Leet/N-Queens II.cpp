// #redo
int __totalNQueens(int n, unsigned long long l, unsigned long long r, unsigned long long d, int begin) {
  if (begin == n) return 1;
  int ans = 0;
  unsigned long long attack = l | r | d;
  for (int i = 0; i < n; ++ i) {
    if ((attack & (1 << i)) == 0) {
      unsigned long long lnext = (l | (1 << i)) << 1;
      unsigned long long rnext = (r | (1 << i)) >> 1;
      unsigned long long dnext = d | (1 << i);
      ans += __totalNQueens(n, lnext, rnext, dnext, begin + 1);
    }
  }
  return ans;
}

int totalNQueens(int n) {
  if (n == 0) return 0; // NOTE: should be clarified
  return __totalNQueens(n, 0, 0, 0, 0);
}
