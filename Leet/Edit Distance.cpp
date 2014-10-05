int minDistance(string word1, string word2) {
  const int N = word1.length();
  const int M = word2.length();
  int res[M + 1][N + 1];
  res[0][0] = 0;
  for (int j = 1; j <= N; j ++) res[0][j] = j;
  for (int i = 1; i <= M; i ++) res[i][0] = i;
  for (int i = 1; i <= M; i ++) {
    for (int j = 1; j <= N; j ++) {
      res[i][j] = min({
          res[i-1][j-1] + (word2[i - 1] != word1[j - 1]),
          res[i-1][j] + 1,
          res[i][j-1] + 1
          });
    }
  }
  return res[M][N];
}

