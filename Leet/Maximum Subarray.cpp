int maxSubArray(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int ans = nums[0];
  int sum = nums[0];
  for (size_t i = 1; i < nums.size(); ++ i) {
    sum = max(nums[i], sum + nums[i]);
    ans = max(ans, sum);
  }
  return ans;
}
