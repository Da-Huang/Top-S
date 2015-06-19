// #redo
// TODO: do it in O(1) space
int rob(vector<int>& nums) {
  const int N = nums.size();
  if (N == 0) return 0;
  if (N == 1) return nums[0];

  int maxAns = 0;
  int rans[N];
  int pre0 = 0, pre1 = 0;
  for (int i = N - 1; i > 0; -- i) {
    int ans0 = max(pre0, pre1);
    int ans1 = pre0 + nums[i];
    pre0 = ans0;
    pre1 = ans1;
    rans[i] = max(ans0, ans1);
  }

  pre0 = 0, pre1 = 0;
  for (int i = 1; i < N; ++ i) {
    int ans0 = max(pre0, pre1);
    int ans1 = pre0 + nums[i];
    pre0 = ans0;
    pre1 = ans1;
    int ans = max(ans0, ans1) - (i == N - 1 ? 0 : rans[i+1]);
    maxAns = max(maxAns, ans);
  }

  pre0 = 0, pre1 = 0;
  for (int i = N - 2; i >= 0; -- i) {
    int ans0 = max(pre0, pre1);
    int ans1 = pre0 + nums[i];
    pre0 = ans0;
    pre1 = ans1;
    rans[i] = max(ans0, ans1);
  }

  pre0 = 0, pre1 = 0;
  for (int i = 0; i < N - 1; ++ i) {
    int ans0 = max(pre0, pre1);
    int ans1 = pre0 + nums[i];
    pre0 = ans0;
    pre1 = ans1;
    int ans = max(ans0, ans1) - (i == N - 2 ? 0 : rans[i+1]);
    maxAns = max(maxAns, ans);
  }

  return maxAns;
}
