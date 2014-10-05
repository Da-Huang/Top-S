bool isInterleave(string s1, string s2, string s3) {
  const int M = s1.length();
  const int N = s2.length();
  const int T = s3.length();
  if ( M + N != T ) return false;
  vector<vector<bool>> res(M + 1, vector<bool>(N + 1));
  res[0][0] = true;
  for (int j = 1; j <= N; j ++)
    res[0][j] = res[0][j - 1] && s2[j - 1] == s3[j - 1];
  for (int i = 1; i <= M; i ++)
    res[i][0] = res[i - 1][0] && s1[i - 1] == s3[i - 1];
  for (int i = 1; i <= M; i ++) {
    for (int j = 1; j <= N; j ++) {
      res[i][j] = res[i - 1][j] && s1[i - 1] == s3[i + j - 1] ||
        res[i][j - 1] && s2[j - 1] == s3[i + j - 1];
    }
  }
  return res[M][N];
}

