bool isIsomorphic(string s, string t) {
  if (s.size() != t.size()) return false;
  char mapping[128];
  memset(mapping, 0, sizeof(mapping));
  bitset<128> mapped;
  for (size_t i = 0; i < s.size(); ++ i) {
    if (mapping[s[i]]) {
      if (mapping[s[i]] != t[i]) return false;
    } else if (mapped[t[i]]) {
      return false;
    } else {
      mapping[s[i]] = t[i];
      mapped[t[i]] = true;
    }
  }
  return true;
}
