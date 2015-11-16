vector<string> summaryRanges(vector<int>& nums) {
  vector<string> ans;
  size_t i = 0;
  for (size_t j = 1; j <= nums.size(); ++ j) {
    if (j == nums.size() || nums[j] > nums[j-1] + 1) {
      if (i + 1 == j) ans.push_back(to_string(nums[i]));
      else ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
      i = j;
    }
  }
  return ans;
}
