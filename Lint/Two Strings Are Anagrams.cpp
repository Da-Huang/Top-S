bool anagram(string s, string t) {
  if (s.size() != t.size()) return false;
  int cmap[128];
  memset(cmap, 0, sizeof(cmap));
  for (char c : s) ++cmap[c];
  for (char c : t) {
    if (--cmap[c] < 0) return false;
  }
  return true;
}
