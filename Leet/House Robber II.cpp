// #redo
int __rob(vector<int> &nums, int begin, int end) {
  int ans = 0;
  int pre0 = 0, pre1 = 0;
  for (int i = begin; i < end; ++ i) {
    int ans0 = max(pre0, pre1);
    int ans1 = pre0 + nums[i];
    ans = max({ans0, ans1, ans});
    pre0 = ans0;
    pre1 = ans1;
  }
  return ans;
}

int rob(vector<int>& nums) {
  const int N = nums.size();
  if (N == 0) return 0;
  if (N == 1) return nums[0];
  return max(__rob(nums, 0, N - 1), __rob(nums, 1, N));
}
