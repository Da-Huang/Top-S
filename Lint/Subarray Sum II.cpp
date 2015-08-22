int subarraySumII(vector<int>& A, int start, int end) {
  const int N = A.size();
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int buffer = 0;
    for (int j = i; j < N; ++j) {
      buffer += A[j];
      if (start <= buffer && buffer <= end) ++ans;
    }
  }
  return ans;
}

// Actually, all elements in A are non-negative.
// #solution2
int subarraySumII(vector<int>& A, int start, int end) {
  const int N = A.size();
  if (N < 2) return 0;
  int k = 0, i = 1, j = 1;
  int sumk = 0, sumi = A[0], sumj = A[0];
  int ans = 0;
  while (k < N) {
    while (i <= N && sumi - sumk < start) {
      if (i < N) sumi += A[i];
      ++i;
    }
    while (j <= N && sumj - sumk <= end) {
      if (j < N) sumj += A[j];
      ++j;
    }
    ans += j - i;
    sumk += A[k++];
    if (k == N) break;
    if (k == i) sumi += A[i++];
    if (k == j) sumj += A[j++];
  }
  return ans;
}
