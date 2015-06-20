int maxProduct(vector<int>& nums) {
  const int N = nums.size();
  if (N == 0) return 0;
  int maxValue = nums[0];
  int minValue = nums[0];
  int ans = nums[0];
  for (int i = 1; i < N; ++ i) {
    int tmp = max({nums[i], minValue * nums[i], maxValue * nums[i]});
    minValue = min({nums[i], minValue * nums[i], maxValue * nums[i]});
    maxValue = tmp;
    ans = max(ans, maxValue);
  }
  return ans;
}
