int trap(int A[], int n) {
  int maxIndex = distance(A, max_element(A, A + n));
  int res = 0;
  int currentMax = 0;
  for (int i = 0; i < maxIndex; i ++) {
    currentMax = max(currentMax, A[i]);
    res += currentMax - A[i];
  }
  currentMax = 0;
  for (int i = n - 1; i > maxIndex; i --) {
    currentMax = max(currentMax, A[i]);
    res += currentMax - A[i];
  }
  return res;
}
