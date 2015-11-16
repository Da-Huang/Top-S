int climbStairs(int n) {
  int ans[2] = {1, 1};
  for (int i = 2; i <= n; ++ i) {
    ans[i&1] += ans[(i+1)&1];
  }
  return ans[n&1];
}
