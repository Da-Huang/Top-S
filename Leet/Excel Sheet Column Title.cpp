// #redo
string convertToTitle(int n) {
  string ans;
  while (n) {
    int p = (n - 1) % 26;
    ans.push_back('A' + p);
    n = (n - 1) / 26;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
