vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  const int N = nums.size();
  int begin = 0;
  while (begin < N) {
    int end = begin + 1;
    while (end < N && nums[end] == nums[begin]) ++ end;
    int first = begin + 1, last = N - 1;
    while (first < last) {
      if (nums[first] + nums[last] + nums[begin] > 0) -- last;
      else if (nums[first] + nums[last] + nums[begin] < 0) ++ first;
      else {
        ans.push_back({nums[begin], nums[first], nums[last]});
        ++ first;
        while (first < last && nums[first] == nums[first-1]) ++ first;
      }
    }
    begin = end;
  }
  return ans;
}
