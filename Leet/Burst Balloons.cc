// #improve
int _GetIndex(int k, int i, int j, int N) {
  return (k - 1) * N * (N + 1) / 2 + i * (2 * N - i + 1) / 2 + j - i;
}

int maxCoins(vector<int>& nums) {
  const int N = nums.size();
  if (N == 0) return 0;
  int* ans = new int[N * N * (N + 1) / 2];
  memset(ans, 0, sizeof(int) * N * N * (N + 1) / 2);
  for (int i = 0; i < N; ++i) {
    for (int k = i + 1; k < N; ++k) {
      ans[_GetIndex(k, i, i, N)] =
          (i > 0 ? nums[i - 1] : 1) * nums[i] * nums[k];
    }
    ans[_GetIndex(N, i, i, N)] = (i > 0 ? nums[i - 1] : 1) * nums[i];
  }
  for (int i = N - 2; i >= 0; --i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k <= N; ++k) {
        int kvalue = k < N ? nums[k] : 1;
        int pvalue = i > 0 ? nums[i - 1] : 1;
        int score = max(
            pvalue * nums[j] * kvalue + ans[_GetIndex(j, i, j - 1, N)],
            nums[j - 1] * nums[j] * kvalue + ans[_GetIndex(k, i, j - 1, N)]);
        for (int u = i; u < j; ++u) {
          score = max(score, nums[u] * nums[j] * kvalue +
                                 ans[_GetIndex(j, u + 1, j - 1, N)] +
                                 ans[_GetIndex(k, i, u, N)]);
        }
        ans[_GetIndex(k, i, j, N)] = score;
      }
    }
  }
  return ans[_GetIndex(N, 0, N - 1, N)];
}
