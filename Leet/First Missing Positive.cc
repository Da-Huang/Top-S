int firstMissingPositive(vector<int>& nums) {
  const int N = nums.size();
  size_t i = 0;
  while (i < N) {
    if (nums[i] > 0 && nums[i] <= N && nums[nums[i] - 1] != nums[i]) {
      swap(nums[nums[i] - 1], nums[i]);

    } else ++ i;
  }
  for (int i = 0; i < N; ++ i) {
    if (nums[i] != i + 1) return i + 1;
  }
  return N + 1;
}
