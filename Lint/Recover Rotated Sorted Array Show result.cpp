void recoverRotatedSortedArray(vector<int> &nums) {
  size_t i;
  for (i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[i - 1]) break;
  }
  if (i >= nums.size()) return;
  reverse(nums.begin(), nums.begin() + i);
  reverse(nums.begin() + i, nums.end());
  reverse(nums.begin(), nums.end());
}
