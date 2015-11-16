int lengthOfLongestSubstring(string s) {
  const int N = s.size();
  bitset<256> has;
  int i = 0, j = 0, ans = 0;
  while (j < N) {
    if (has[s[j]]) {
      has[s[i]] = false;
      ++ i;
    } else {
      has[s[j]] = true;
      ++ j;
      ans = max(j - i, ans);
    }
  }
  return ans;
}
