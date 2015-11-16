// #redo
bool isMatch(string s, string p) {
  vector<vector<bool>> ans(s.size()+1, vector<bool>(p.size()+1));
  ans[0][0] = true;
  for (size_t i = 1; i <= s.size(); ++ i) ans[i][0] = false;
  for (size_t i = 0; i <= s.size(); ++ i) {
    for (size_t j = 1; j <= p.size(); ++ j) {
      if (p[j-1] == '*') ans[i][j] = ans[i][j-2] || (i > 0 && ans[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2]));
      else ans[i][j] = i > 0 && ans[i-1][j-1] && (p[j-1] == '.' || s[i-1] == p[j-1]);
    }
  }
  return ans[s.size()][p.size()];
}
