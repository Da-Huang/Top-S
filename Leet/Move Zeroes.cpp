void moveZeroes(vector<int>& nums) {
  int len = 0;
  for (int i = 0; i < (int)nums.size(); ++i) {
    if (nums[i]) {
      nums[len++] = nums[i];
    }
  }
  while (len < (int)nums.size()) nums[len++] = 0;
}
