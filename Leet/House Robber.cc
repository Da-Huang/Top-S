int rob(vector<int>& nums) {
  int ans[3];
  memset(ans, 0, sizeof(ans));
  for (size_t i = 0; i < nums.size(); ++ i) {
    ans[i%3] = max(ans[i%3], ans[(i+1)%3]) + nums[i];
  }
  return max(ans[(nums.size()+1)%3], ans[(nums.size()+2)%3]);
}
