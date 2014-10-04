bool isValid(string s) {
  const int N = s.length();
  char stk[N]; // stack
  int stkLen = 0; // length of stack
  for (int i = 0; i < N; i ++) {
    if ( s[i] == '(' || s[i] == '[' || s[i] == '{' ) stk[stkLen ++] = s[i];
    else if ( s[i] == ')' ) {
      if ( stkLen == 0 || stk[stkLen - 1] != '(' ) return false;
      stkLen --;

    } else if ( s[i] == ']' ) {
      if ( stkLen == 0 || stk[stkLen - 1] != '[' ) return false;
      stkLen --;

    } else { // s[i] == '}'
      if ( stkLen == 0 || stk[stkLen - 1] != '{' ) return false;
      stkLen --;
    }
  }
  return stkLen == 0;
}

