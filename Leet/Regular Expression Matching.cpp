bool isMatch(const char *s, const char *p) {
  const int N = strlen(s);
  const int M = strlen(p);
  unordered_set<int> res[M + 1];
  res[0].insert(0);
  int i = 0;
  while ( i < M ) {
    if ( i + 1 < M && p[i + 1] == '*' ) {
      for (auto &j : res[i]) {
        res[i + 2].insert(j);
        for (int k = j; k < N; k ++) {
          if ( p[i] == '.' || p[i] == s[k] ) {
            res[i + 2].insert(k + 1);

          } else break;
        }
      }
      i += 2;

    } else {
      for (auto &j : res[i]) {
        if ( p[i] == '.' || p[i] == s[j] ) {
          res[i + 1].insert(j + 1);
        }
      }
      i ++;
    }
  }
  return res[M].find(N) != res[M].end();
}

