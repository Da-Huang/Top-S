bool isAnagram(string s, string t) {
  if (s.size() != t.size()) return false;
  int cmap[26];
  memset(cmap, 0, sizeof(cmap));
  for (char c : s) ++cmap[c-'a'];
  for (char c : t) {
    if (--cmap[c-'a'] < 0) return false;
  }
  return true;
}
