// #redo
int longestIncreasingContinuousSubsequence(vector<int>& A) {
  int ans_inc = 0, ans_dec = 0;
  int inc = 0, dec = 0;
  for (int i = 0; i < (int)A.size(); ++i) {
    if (i == 0 || A[i] == A[i-1]) {
      inc = dec = 1;
    } else if (A[i] > A[i-1]) {
      ++inc;
      dec = 1;
    } else { // A[i] < A[i-1]
      ++dec;
      inc = 1;
    }
    ans_inc = max(ans_inc, inc);
    ans_dec = max(ans_dec, dec);
  }
  return max(ans_inc, ans_dec);
}
