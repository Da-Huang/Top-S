// #redo
string removeDuplicateLetters(string s) {
  int count[26];
  memset(count, 0, sizeof(count));
  for (char c : s) ++count[c - 'a'];
  int cset[26];
  memset(cset, 0, sizeof(cset));
  string ans;
  int i = 0, j = 0;
  while (j < (int)s.size()) {
    if (count[s[j] - 'a'] == 0)
      ++j;
    else if (count[s[j] - 'a'] > 1) {
      --count[s[j] - 'a'];
      ++cset[s[j] - 'a'];
      ++j;
    } else {
      char c = s[j];
      for (c = 'a'; c < s[j]; ++c) {
        if (cset[c - 'a'] > 0) break;
      }
      while (s[i] != c) {
        --cset[s[i] - 'a'];
        ++i;
      }
      ans.push_back(c);
      cset[c - 'a'] = 0;
      count[c - 'a'] = 0;
    }
  }
  return ans;
}
