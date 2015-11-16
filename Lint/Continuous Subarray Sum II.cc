// #redo
vector<int> continuousSubarraySumII(vector<int>& A) {
  const int N = A.size();
  if (N == 0) return {};
  int ans = A[0];
  int ans_first = 0, ans_last = 0;
  int sum = A[0];
  int first = 0;
  int all_sum = A[0];
  int min_sum = A[0];
  int min_first = 0;
  int min_all_first = 0, min_all_last = 0;
  int min_all = A[0];
  for (int i = 1; i < N; ++i) {
    all_sum += A[i];
    
    if (min_sum > 0) {
      min_sum = A[i];
      min_first = i;
    } else {
      min_sum += A[i];
    }
    if (min_sum < min_all) {
      min_all = min_sum;
      min_all_first = min_first;
      min_all_last = i;
    }
    
    if (sum < 0) {
      sum = A[i];
      first = i;
    } else {
      sum += A[i];
    }
    
    if (sum > ans) {
      ans = sum;
      ans_first = first;
      ans_last = i;
    }
  }
  if (min_all_first > 0 && min_all_last < N - 1 && all_sum - min_all > ans)
    return {min_all_last+1, min_all_first-1};
  return {ans_first, ans_last};
}
