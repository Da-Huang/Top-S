void partitionArray(vector<int> &nums) {
  int i = 0, j = (int)nums.size();
  while (i < j) {
    if (nums[i] & 1) ++i;
    else if (!(nums[j] & 1)) --j;
    else {
      swap(nums[i], nums[j]);
      ++i;
      --j;
    }
  }
}
