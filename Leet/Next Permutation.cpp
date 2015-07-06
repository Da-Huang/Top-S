void nextPermutation(vector<int>& nums) {
  const int N = nums.size();
  int i = N - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) -- i;
  if (i >= 0) {
    int j = N - 1;
    while (nums[j] <= nums[i]) -- j;
    swap(nums[i], nums[j]);
  }
  reverse(nums.begin() + i + 1, nums.end());
}
