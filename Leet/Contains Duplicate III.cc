// #redo
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  if (t < 0) return false;
  const int N = nums.size();
  set<int> SET;
  for (int i = 0; i < N; ++ i) {
    if (i > k) SET.erase(nums[i-k-1]);
    auto it = SET.insert(nums[i]);
    if (!it.second) return true;

    if (it.first != SET.begin()) {
      auto jt = prev(it.first);
      if (*jt < 0) {
        if (nums[i] <= t + *jt) return true;
      } else {
        if (nums[i] - *jt <= t) return true;
      }
    }
    if (it.first != prev(SET.end())) {
      auto jt = next(it.first);
      if (nums[i] < 0) {
        if (*jt <= t + nums[i]) return true;
      } else {
        if (*jt - nums[i] <= t) return true;
      }
    }
  }
  return false;
}
