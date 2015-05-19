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
  if (N == 0) return -1;
  int i = 1;
  int next = 0 + nums[0];
  int ans = 0;
  while (i < N) {
    ++ ans;
    int newNext = next;
    for (int j = i; j <= next && j < N; ++ j) {
      newNext = max(newNext, j + nums[j]);
    }
    if (newNext == next && next < N - 1) return -1;

    i = next + 1;
    next = newNext;
  }
  return ans;
}
