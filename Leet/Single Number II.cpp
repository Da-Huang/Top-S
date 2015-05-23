int singleNumber(vector<int>& nums) {
  int ans = 0;
  for (int k = 0; k < 32; ++ k) {
    int count = 0;
    for (auto n : nums) {
      count += (n >> k) & 1;
    }
    if (count % 3) ans |= 1 << k;
  }
  return ans;
}
