bool isNumber(string s) {
  int N = s.size();
  while (N > 0 && s[N-1] == ' ') -- N;
  int i = 0;
  while (i < N && s[i] == ' ') ++ i;
  if (i == N) return false;
  if (s[i] == '+' || s[i] == '-') ++ i;
  bool hasDigit = false;
  while (i < N && isdigit(s[i])) {
    hasDigit = true;
    ++ i;
  }
  if (i < N && s[i] == '.') {
    ++ i;
    while (i < N && isdigit(s[i])) {
      hasDigit = true;
      ++ i;
    }
  }
  if (!hasDigit) return false;
  if (i == N) return true;
  if (s[i] != 'e' && s[i] != 'E') return false;
  ++ i;
  if (i < N && (s[i] == '+' || s[i] == '-')) ++ i;
  hasDigit = false;
  while (i < N && isdigit(s[i])) {
    hasDigit = true;
    ++ i;
  }
  return i == N && hasDigit;
}
