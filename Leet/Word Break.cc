bool wordBreak(string s, unordered_set<string>& wordDict) {
  const int N = s.size();
  vector<bool> able(N + 1, false);
  able[0] = true;
  for (int i = 1; i <= N; ++ i) {
    for (int j = 0; j < i; ++ j) {
      if (able[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
        able[i] = true;
        break;
      }
    }
  }
  return able[N];
}
