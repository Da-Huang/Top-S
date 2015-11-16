// #redo
int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  const int N = nums.size();
  assert(N >= 3);
  int ans = nums[0] + nums[1] + nums[2];
  for (int k = 0; k + 2 < N; ++ k) {
    int i = k + 1, j = N - 1;
    while (i < j) {
      if (nums[k] + nums[i] + nums[j] > target) {
        if (abs(ans - target) > nums[k] + nums[i] + nums[j] - target) {
          ans = nums[k] + nums[i] + nums[j];
        }
        -- j;
      } else if (nums[k] + nums[i] + nums[j] < target) {
        if (abs(ans - target) > target - nums[k] - nums[i] - nums[j]) {
          ans = nums[k] + nums[i] + nums[j];
        }
        ++ i;
      } else return target;
    }
  }
  return ans;
}
