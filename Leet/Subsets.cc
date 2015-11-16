void __subsets(vector<int> &nums, int begin, vector<int> &v, vector<vector<int>> &ans) {
  if (begin == (int) nums.size()) {
    ans.push_back(v);
    return;
  }

  __subsets(nums, begin+1, v, ans);
  v.push_back(nums[begin]);
  __subsets(nums, begin+1, v, ans);
  v.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  vector<int> v;
  __subsets(nums, 0, v, ans);
  return ans;
}
