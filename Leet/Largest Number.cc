// #redo
string largestNumber(vector<int>& nums) {
  sort(nums.begin(), nums.end(), [](int i, int j) {
      string si = to_string(i) + to_string(j);
      string sj = to_string(j) + to_string(i);
      for (size_t k = 0; k < si.size(); ++ k) {
      if (si[k] > sj[k]) return true;
      if (si[k] < sj[k]) return false;
      }
      return false;
      });
  string ans;
  for (int n : nums) ans += to_string(n);
  if (nums.size() == 0 || ans[0] == '0') return "0";
  return ans;
}
