int romanToInt(string s) {
  int ROMAN[128];
  ROMAN['I'] = 1;
  ROMAN['V'] = 5;
  ROMAN['X'] = 10;
  ROMAN['L'] = 50;
  ROMAN['C'] = 100;
  ROMAN['D'] = 500;
  ROMAN['M'] = 1000;

  int ans = 0;
  size_t i = 0;
  while (i + 1 < s.size()) {
    if (ROMAN[s[i]] * 5 == ROMAN[s[i+1]] || ROMAN[s[i]] * 10 == ROMAN[s[i+1]]) {
      ans += ROMAN[s[i+1]] - ROMAN[s[i]];
      i += 2;
    } else {
      ans += ROMAN[s[i ++]];
    }
  }
  if (i < s.size()) ans += ROMAN[s[i]];
  return ans;
}
