// #redo
int minDistance(string word1, string word2) {
  const int M = word1.size();
  const int N = word2.size();
  int ans[2][N+1];
  for (int j = 0; j <= N; ++ j) ans[0][j] = j;
  for (int i = 1; i <= M; ++ i) {
    ans[i&1][0] = i;
    for (int j = 1; j <= N; ++ j) {
      ans[i&1][j] = min({
          1 + ans[i&1][j-1],
          1 + ans[(i-1)&1][j],
          word1[i-1] == word2[j-1] ? ans[(i-1)&1][j-1] : ans[(i-1)&1][j-1] + 1
          });
    }
  }
  return ans[M&1][N];
}
