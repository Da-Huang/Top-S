// #redo
int myAtoi(string str) {
  const int N = str.size();
  int i = 0;
  while (i < N && str[i] == ' ') ++ i;
  if (i == N) return 0;

  int ans = 0;
  bool isNegative = false;
  if (str[i] == '+') ++ i;
  else if (str[i] == '-') {
    isNegative = true;
    ++ i;
  }

  while (i < N && isdigit(str[i])) {
    int p = str[i] - '0';
    if (ans < (INT_MIN + p) / 10) return isNegative ? INT_MIN : INT_MAX;
    ans = ans * 10 - p;
    ++ i;
  }
  return isNegative ? ans : ans == INT_MIN ? INT_MAX : -ans;
}
