// #redo
void __subsetWithDup(vector<int> &nums, vector<int> &v, vector<vector<int>> &ans, size_t begin) {
  if (begin == nums.size()) {
    ans.push_back(v);
    return;
  }
  size_t end = begin + 1;
  while (end < nums.size() && nums[begin] == nums[end]) ++ end;
  __subsetWithDup(nums, v, ans, end);
  for (size_t i = begin + 1; i <= end; ++ i) {
    v.push_back(nums[begin]);
    __subsetWithDup(nums, v, ans, end);
  }
  v.erase(v.end() - end + begin, v.end());
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  vector<int> v;
  __subsetWithDup(nums, v, ans, 0);
  return ans;
}
