// #redo
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  const int N = nums.size();
  vector<vector<int>> ans;
  if (N < 4) return ans;
  sort(nums.begin(), nums.end());
  for (int i = 0; i + 3 < N; ++ i) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    for (int j = i + 1; j + 2 < N; ++ j) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;
      int first = j + 1, last = N - 1;
      while (first < last) {
        if (nums[i] + nums[j] + nums[first] + nums[last] > target) -- last;
        else if (nums[i] + nums[j] + nums[first] + nums[last] < target) ++ first;
        else {
          ans.push_back({nums[i], nums[j], nums[first], nums[last]});
          do ++ first; while (first < last && nums[first] == nums[first - 1]);
        }
      }
    }
  }
  return ans;
}
