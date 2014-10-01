vector<string> wordBreakInner(const string &s, const unordered_set<string> &dict, 
    vector<string> cache[], vector<bool> &cacheValid, int start=0) {
  const int N = s.length();
  vector<string> res;
  if ( start == N ) {
    res.push_back("");
    return res;
  }
  if ( cacheValid[start] ) return cache[start];

  for (int i = start; i < N; i ++) {
    if ( dict.find(s.substr(start, i + 1 - start)) != dict.end() ) {
      vector<string> subRes = wordBreakInner(s, dict, cache, cacheValid, i + 1);
      for (auto &item : subRes) {
        if ( item.length() > 0 ) item.insert(0, " ");
        item.insert(0, s.substr(start, i + 1 - start));
        res.push_back(item);
      }
    }
  }
  cacheValid[start] = true;
  return cache[start] = res;
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
  vector<string> cache[s.length()];
  vector<bool> cacheValid(s.length(), false);
  return wordBreakInner(s, dict, cache, cacheValid);
}
