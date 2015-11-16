void __popSymbolStk(stack<char> &symbol_stk, vector<string> &ans,
                    const string &stops) {
  while (!symbol_stk.empty()) {
    int i;
    for (i = 0; i < (int)stops.size(); ++i) {
      if (symbol_stk.top() == stops[i]) break;
    }
    if (i < (int)stops.size()) break;
    ans.push_back(string(1, symbol_stk.top()));
    symbol_stk.pop();
  }
}

vector<string> convertToRPN(vector<string> &expression) {
  vector<string> ans;
  stack<char> symbol_stk;
  for (const string &token : expression) {
    if (isdigit(token.back()))
      ans.push_back(token);
    else {
      switch (token.back()) {
        case '(':
          symbol_stk.push(token.back());
          break;
        case ')':
          __popSymbolStk(symbol_stk, ans, "(");
          symbol_stk.pop();
          break;
        case '+':
        case '-':
          __popSymbolStk(symbol_stk, ans, "(");
          symbol_stk.push(token.back());
          break;
        case '*':
        case '/':
          __popSymbolStk(symbol_stk, ans, "(+-");
          symbol_stk.push(token.back());
          break;
      }
    }
  }
  __popSymbolStk(symbol_stk, ans, "");
  return ans;
}
