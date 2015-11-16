// #redo
int lengthOfLongestSubstringKDistinct(string s, int k) {
  int cmap[128];
  int count = 0;
  memset(cmap, 0, sizeof(cmap));
  int ans = 0;
  int i = 0, j = 0;
  while (j < (int)s.size()) {
    if (cmap[s[j]] == 0 && count == k) {
      if (--cmap[s[i++]] == 0) --count;
    } else {
      if (cmap[s[j++]]++ == 0) ++count;
      ans = max(ans, j - i);
    }
  }
  return ans;
}
