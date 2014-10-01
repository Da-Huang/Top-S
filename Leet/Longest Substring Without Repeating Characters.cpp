int lengthOfLongestSubstring(string s) {
  const int N = s.length();
  vector<bool> dict(256, false);
  int i = 0, j = 0;
  int res = 0;
  while ( j < N ) {
    if ( !dict[s[j]] ) {
      dict[s[j]] = true;
      j ++;
      res = max(res, j - i);

    } else {
      dict[s[i]] = false;
      i ++;
    }
  }
  return res;
}
