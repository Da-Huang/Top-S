int numDistinct(string S, string T) {
  const int M = S.length();
  const int N = T.length();
  int res[M + 1][N + 1];
  res[0][0] = 1;
  for (int i = 1; i <= M; i ++) res[i][0] = 1;
  for (int j = 1; j <= N; j ++) res[0][j] = 0;
  for (int i = 1; i <= M; i ++) {
    for (int j = 1; j <= N; j ++) {
      res[i][j] = res[i - 1][j];
      if ( S[i - 1] == T[j - 1] ) res[i][j] += res[i - 1][j - 1];
    }
  }
  return res[M][N];
}

