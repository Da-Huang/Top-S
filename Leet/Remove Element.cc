int removeElement(vector<int>& nums, int val) {
  size_t i = 0, j = 0;
  for (size_t i = 0; i < nums.size(); ++ i) {
    if (nums[i] != val) nums[j ++] = nums[i];
  }
  return j;
}
