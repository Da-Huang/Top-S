bool canJump(vector<int>& nums) {
  size_t k = 0;
  for (size_t i = 0; i < nums.size(); ++ i) {
    if (k < i) return false;
    k = max(k, i + nums[i]);
  }
  return true;
}
