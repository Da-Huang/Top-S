// #redo
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_set<int> SET;
  for (size_t i = 0; i < nums.size(); ++ i) {
    if (i > (size_t) k) SET.erase(nums[i-k-1]);
    auto it = SET.insert(nums[i]);
    if (!it.second) return true;
  }
  return false;
}
