bool wordBreak(string s, unordered_set<string> &dict) {
  const int N = s.length();
  vector<bool> res(N + 1, false);
  res[0] = true;
  for (int i = 1; i <= N; i ++) {
    for (int j = 0; j < i; j ++) {
      if ( res[j] && dict.find(s.substr(j, i - j)) != dict.end() ) {
        res[i] = true;
        break;
      }
    }
  }
  return res[N];
}

