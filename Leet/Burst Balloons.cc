// #redo
int maxCoins(vector<int>& nums) {
  const int N = nums.size();
  if (N == 0) return 0;
  int ans[N][N];
  for (int i = 0; i < N; ++i) {
    int lval = i > 0 ? nums[i - 1] : 1;
    int rval = i + 1 < N ? nums[i + 1] : 1;
    ans[i][i] = lval * nums[i] * rval;
    if (i + 1 < N) ans[i + 1][i] = 0;
  }
  for (int i = N - 2; i >= 0; --i) {
    int lval = i > 0 ? nums[i - 1] : 1;
    for (int j = i + 1; j < N; ++j) {
      int rval = j + 1 < N ? nums[j + 1] : 1;
      int max_val = 0;
      for (int k = i; k <= j; ++k) {
        int lsum = k > 0 ? ans[i][k - 1] : 0;
        int rsum = k + 1 < N ? ans[k + 1][j] : 0;
        max_val = max(max_val, lsum + rsum + lval * nums[k] * rval);
      }
      ans[i][j] = max_val;
    }
  }
  return ans[0][N - 1];
}
