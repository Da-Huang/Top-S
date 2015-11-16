// #redo
bool isScramble(string s1, string s2) {
  if (s1 == s2) return true;
  string s1c = s1, s2c = s2;
  sort(s1c.begin(), s1c.end());
  sort(s2c.begin(), s2c.end());
  if (s1c != s2c) return false;

  for (size_t i = 1; i < s1.size(); ++ i) {
    if (isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s1.size()-i)) ||
        isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
      return true;
  }
  return false;
}
