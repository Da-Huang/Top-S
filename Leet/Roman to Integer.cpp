int romanToInt(string s) {
  const int N = s.length();
  int ROMAN[128];
  ROMAN['I'] = 1;
  ROMAN['V'] = 5;
  ROMAN['X'] = 10;
  ROMAN['L'] = 50;
  ROMAN['C'] = 100;
  ROMAN['D'] = 500;
  ROMAN['M'] = 1000;
  int res = 0;
  int i = 0;
  while ( i < N ) {
    if ( i + 1 < N ) {
      if ( ROMAN[s[i]] * 5 == ROMAN[s[i + 1]] || ROMAN[s[i]] * 10 == ROMAN[s[i + 1]] ) {
        res += ROMAN[s[i + 1]] - ROMAN[s[i]];
        i += 2;
        continue;
      }
    }
    res += ROMAN[s[i]];
    i ++;
  }
  return res;
}
