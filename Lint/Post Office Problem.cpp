// TODO: use O(n^2) algorithm.
int postOffice(vector<int>& A, int k) {
  sort(A.begin(), A.end());
  const int N = A.size();
  if (N == 0) return 0;
  if (k == 0) return INT_MAX;

  // get distances between [i, j]
  int dist[N][N];
  dist[0][0] = 0;
  for (int i = 1; i < N; ++i) {
    dist[i][i] = 0;
    dist[i - 1][i] = A[i] - A[i - 1];
  }
  for (int i = N - 1; i >= 0; --i) {
    for (int j = i + 2; j < N; ++j) {
      dist[i][j] = dist[i + 1][j - 1] + A[j] - A[i];
    }
  }

  int ans[N][k];
  for (int j = 0; j < k; ++j) ans[0][j] = 0;
  for (int i = 0; i < N; ++i) ans[i][0] = dist[0][i];
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < k; ++j) {
      int val = dist[0][i];
      for (int l = 0; l < i; ++l) {
        val = min(val, ans[l][j - 1] + dist[l + 1][i]);
      }
      ans[i][j] = val;
    }
  }
  return ans[N - 1][k - 1];
}
