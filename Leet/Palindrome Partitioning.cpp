vector<vector<string>> __partition(string &s, vector<vector<bool>> palin, int begin, 
    vector<vector<string>> cache[], vector<bool> &cacheValid) {
  vector<vector<string>> res;
  const int N = s.length();
  if ( begin == N ) {
    res.push_back(vector<string>());
    return res;
  }
  if ( cacheValid[begin] ) return cache[begin];

  for (int i = begin; i < N; i ++) {
    if ( palin[begin][i] ) {
      string part = s.substr(begin, i + 1 - begin);
      vector<vector<string>> subRes = __partition(s, palin, i + 1, cache, cacheValid);
      for (auto &v : subRes) {
        v.insert(v.begin(), part);
        res.push_back(v);
      }
    }
  }
  cacheValid[begin] = true;
  return cache[begin] = res;
}

vector<vector<string>> partition(string s) {
  const int N = s.length();
  if ( N == 0 ) return vector<vector<string>>();

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
  vector<vector<string>> cache[N];
  vector<bool> cacheValid(N, false);
  return __partition(s, palin, 0, cache, cacheValid);
}

