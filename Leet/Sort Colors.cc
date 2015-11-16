// #redo
void sortColors(vector<int>& nums) {
  int tail0 = 0, tail1 = 0, i = 0;
  for (int i = 0; i < (int) nums.size(); ++ i) {
    int num = nums[i];
    if (num == 1) {
      nums[i] = nums[tail1];
      nums[tail1 ++] = num;
    } else if (num == 0) {
      nums[i] = nums[tail1];
      nums[tail1 ++] = nums[tail0];
      nums[tail0 ++] = num;
    }
  }
}
