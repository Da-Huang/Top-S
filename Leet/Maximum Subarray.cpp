int maxSubArray(int A[], int n) {
  int cur = A[0];
  int res = cur;
  for (int i = 1; i < n; i ++) {
    cur = max(cur + A[i], A[i]);
    res = max(res, cur);
  }
  return res;
}

