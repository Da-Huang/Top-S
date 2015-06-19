int numDistinct(string s, string t) {
  int ans[s.size()+1][t.size()+1];
  ans[0][0] = 1;
  for (int i = 1; i <= s.size(); ++ i) ans[i][0] = 1;
  for (int j = 1; j <= t.size(); ++ j) ans[0][j] = 0;
  for (int i = 1; i <= s.size(); ++ i) {
    for (int j = 1; j <= t.size(); ++ j) {
      ans[i][j] = ans[i-1][j];
      if (s[i-1] == t[j-1]) ans[i][j] += ans[i-1][j-1];
    }
  }
  return ans[s.size()][t.size()];
}
