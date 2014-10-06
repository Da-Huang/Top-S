int evalRPN(vector<string> &tokens) {
  const int N = tokens.size();
  int stk[N];
  int stkLen = 0;
  for (int i = 0; i < N; i ++) {
    if ( tokens[i] == "+" ) {
      stkLen --;
      stk[stkLen - 1] = stk[stkLen - 1] + stk[stkLen];

    } else if ( tokens[i] == "-" ) {
      stkLen --;
      stk[stkLen - 1] = stk[stkLen - 1] - stk[stkLen];

    } else if ( tokens[i] == "*" ) {
      stkLen --;
      stk[stkLen - 1] = stk[stkLen - 1] * stk[stkLen];

    } else if ( tokens[i] == "/" ) {
      stkLen --;
      stk[stkLen - 1] = stk[stkLen - 1] / stk[stkLen];

    } else stk[stkLen ++] = stoi(tokens[i]);
  }
  return stk[0];
}

