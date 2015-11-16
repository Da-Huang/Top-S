// #redo
vector<int> continuousSubarraySum(vector<int>& A) {
  const int N = A.size();
  if (N == 0) return {};
  int ans = A[0];
  int ans_first = 0, ans_last = 0;
  int first = 0;
  int sum = A[0];
  for (int i = 1; i < N; ++i) {
    // sum = max(A[i], sum + A[i]);
    // ans = max(ans, sum);
    if (sum < 0) {
      sum = A[i];
      first = i;
    } else {
      sum += A[i];
    }
    if (ans < sum) {
      ans = sum;
      ans_first = first;
      ans_last = i;
    }
  }
  return {ans_first, ans_last};
}
