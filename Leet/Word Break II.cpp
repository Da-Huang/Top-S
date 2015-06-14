vector<string> wordBreakInner(const string &s, const unordered_set<string> &dict, vector<string> cache[], vector<bool> &cacheValid, int start=0) {
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


// #redo
// #version2
bool __wordBreak(string &s, unordered_set<string>& wordDict, size_t begin, string &v, vector<bool> &able, vector<string> &ans) {
  if (begin == s.size()) {
    ans.push_back(v);
    return true;
  }
  if (!able[begin]) return false;

  bool ansAble = false;
  for (size_t end = begin + 1; end <= s.size(); ++ end) {
    string word = s.substr(begin, end - begin);
    if (wordDict.find(word) != wordDict.end()) {
      size_t size = v.size();
      if (!v.empty()) v += " ";
      v += word;
      ansAble |= __wordBreak(s, wordDict, end, v, able, ans);
      v.resize(size);
    }
  }
  return able[begin] = ansAble;
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
  vector<string> ans;
  string v;
  vector<bool> able(s.size(), true);
  __wordBreak(s, wordDict, 0, v, able, ans);
  return ans;
}
