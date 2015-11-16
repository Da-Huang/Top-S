int longestConsecutive(vector<int>& nums) {
  int ans = 0;
  unordered_set<int> SET(nums.begin(), nums.end());
  for (int n : nums) {
    auto it = SET.find(n);
    if (it != SET.end()) {
      int len = 0;
      int i = n;
      do {
        SET.erase(i ++);
        ++ len;
      } while (SET.find(i) != SET.end());
      i = n - 1;
      while (SET.find(i) != SET.end()) {
        SET.erase(i --);
        ++ len;
      }
      ans = max(ans, len);
    }
  }
  return ans;
}
