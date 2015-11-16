void nextPermutation(vector<int> &nums) {
  const int N = nums.size();
  int i = N - 1;
  while (i > 0 && nums[i] <= nums[i - 1]) --i;
  if (i > 0) {
    for (int j = N - 1; j >= i; --j) {
      if (nums[j] > nums[i - 1]) {
        swap(nums[j], nums[i - 1]);
        break;
      }
    }
  }
  reverse(nums.begin() + i, nums.end());
}
