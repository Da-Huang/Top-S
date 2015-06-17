bool containsDuplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  for (size_t i = 1; i < nums.size(); ++ i) {
    if (nums[i] == nums[i - 1]) return true;
  }
  return false;
}

// #version2
bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> SET(nums.begin(), nums.end());
  return SET.size() < nums.size();
}
