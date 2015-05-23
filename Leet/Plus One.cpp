vector<int> plusOne(vector<int>& digits) {
  const int N = digits.size();
  vector<int> ans;
  int c = 1;
  for (int i = N - 1; i >= 0; -- i) {
    int p = digits[i] + c;
    ans.push_back(p % 10);
    c = p / 10;
  }
  if (c) ans.push_back(c);
  reverse(ans.begin(), ans.end());
  return ans;
}
