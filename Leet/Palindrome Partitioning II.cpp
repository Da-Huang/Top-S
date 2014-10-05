int minCut(string s) {
  const int N = s.length();
  if ( N == 0 ) return 0;
  vector<vector<bool>> palin(N, vector<bool>(N));
  palin[0][0] = true;
  for (int i = 1; i < N; i ++) {
    palin[i][i] = true;
    palin[i - 1][i] = s[i - 1] == s[i];
  }
  for (int i = N - 3; i >= 0; i --) {
    for (int j = i + 2; j < N; j ++) {
      palin[i][j] = palin[i + 1][j - 1] && s[i] == s[j];
    }
  }
  int res[N];
  res[0] = 0;
  for (int i = 1; i < N; i ++) {
    if ( palin[0][i] ) res[i] = 0;
    else {
      int can = i;
      for (int j = 0; j < i; j ++) {
        if ( palin[j + 1][i] ) {
          can = min(can, res[j] + 1);
        }
      }
      res[i] = can;
    }
  }
  return res[N - 1];
}

