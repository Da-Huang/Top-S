int __longestIncreasingContinuousSubsequenceII(vector<vector<int>> &A, int i,
                                               int j,
                                               vector<vector<int>> &ans) {
  if (ans[i][j] > 0) return ans[i][j];
  int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  ans[i][j] = 1;
  for (int k = 0; k < 4; ++k) {
    int ii = i + directions[k][0];
    int jj = j + directions[k][1];
    if (ii >= 0 && jj >= 0 && ii < (int)A.size() && jj < (int)A[0].size() &&
        A[ii][jj] < A[i][j]) {
      ans[i][j] = max(ans[i][j], 1 + __longestIncreasingContinuousSubsequenceII(
                                         A, ii, jj, ans));
    }
  }
  return ans[i][j];
}

int longestIncreasingContinuousSubsequenceII(vector<vector<int>> &A) {
  const int M = A.size();
  if (M == 0) return 0;
  const int N = A[0].size();
  if (N == 0) return 0;

  vector<vector<int>> ans(M, vector<int>(N, 0));
  int ans_value = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      ans_value = max(ans_value,
                      __longestIncreasingContinuousSubsequenceII(A, i, j, ans));
    }
  }
  return ans_value;
}
