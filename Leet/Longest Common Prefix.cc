string longestCommonPrefix(vector<string>& strs) {
  const int M = strs.size();
  if (M == 0) return "";
  const int N = strs[0].size();
  int j;
  for (j = 0; j < N; ++ j) {
    for (int i = 1; i < M; ++ i) {
      if (strs[0][j] != strs[i][j]) return strs[0].substr(0, j);
    }
  }
  return strs[0].substr(0, j);
}
