// #redo
bool isInterleave(string s1, string s2, string s3) {
  const int s1n = s1.size();
  const int s2n = s2.size();
  if (s1n + s2n != (int) s3.size()) return false;
  vector<vector<bool>> ans(s1n+1, vector<bool>(s2n+1));
  ans[0][0] = true;
  for (int j = 1; j <= s2n; ++ j) ans[0][j] = ans[0][j-1] && s2[j-1] == s3[j-1];
  for (int i = 1; i <= s1n; ++ i) {
    ans[i][0] = ans[i-1][0] && s1[i-1] == s3[i-1];
    for (int j = 1; j <= s2n; ++ j) {
      ans[i][j] = (ans[i-1][j] && s1[i-1] == s3[i+j-1]) || (ans[i][j-1] && s2[j-1] == s3[i+j-1]);
    }
  }
  return ans[s1n][s2n];
}
