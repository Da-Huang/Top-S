// Redo
int longestValidParentheses(string s) {
  const int N = s.length();
  int stk[N];
  int stkLen = 0;
  int res = 0;
  int begin = 0;
  for (int i = 0; i < N; i ++) {
    if ( s[i] == '(' ) stk[stkLen ++] = i;
    else if ( stkLen > 0 ) {
      stkLen --;
      const int len = stkLen == 0 ? i + 1 - begin : i - stk[stkLen - 1];
      res = max(res, len);
    } else {
      begin = i + 1;
    }
  }
  return res;
}

