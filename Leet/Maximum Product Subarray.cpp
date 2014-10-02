int maxProduct(int A[], int n) {
  if ( n == 0 ) return 0;
  int minRes = A[0];
  int maxRes = A[0];
  int res = A[0];
  for (int i = 1; i < n; i ++) {
    int newMinRes = min({minRes * A[i], maxRes * A[i], A[i]});
    int newMaxRes = max({minRes * A[i], maxRes * A[i], A[i]});
    minRes = newMinRes;
    maxRes = newMaxRes;
    res = max(res, maxRes);
  }
  return res;
}

