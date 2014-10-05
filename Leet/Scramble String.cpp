bool __solve(string s1, string s2) {
  const int N = s1.length();
  if ( s1 == s2 ) return true;
  string ss1 = s1;
  string ss2 = s2;
  sort(ss1.begin(), ss1.end());
  sort(ss2.begin(), ss2.end());
  if ( ss1 != ss2 ) return false;
  for (int i = 1; i < N; i ++) {
    if ( __solve(s1.substr(0, i), s2.substr(0, i)) && __solve(s1.substr(i), s2.substr(i)) ) return true;
    if ( __solve(s1.substr(0, i), s2.substr(N - i)) && __solve(s1.substr(i), s2.substr(0, N - i)) ) return true;
  }
  return false;
}

bool isScramble(string s1, string s2) {
  if ( s1.length() != s2.length() ) return false;
  return __solve(s1, s2);
}

