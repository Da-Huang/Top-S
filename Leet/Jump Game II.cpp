// #redo
int jump(int A[], int n) {
  int res[n];
  if ( n <= 1 ) return 0;
  res[0] = 0;
  int bound = 1;
  for (int i = 0; i < n - 1; i ++) {
    int j = i + A[i];
    if ( j >= n - 1 ) return res[i] + 1;
    while ( bound <= j ) res[bound ++] = res[i] + 1;
  }
  // A[n - 1] is not reachable.
  return -1;
}


// #redo
// #version2
int jump(vector<int>& nums) {
  const int N = nums.size();
  int j = 0, ans = 0, k = 0;
  for (int i = 0; i < N; ++ i) {
    if (k < i) return -1;
    if (i > j) {
      ++ ans;
      j = k;
    }
    k = max(k, i + nums[i]);
  }
  return ans;
}
