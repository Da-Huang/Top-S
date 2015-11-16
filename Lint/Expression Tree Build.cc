// #redo
void __pop_symbol_stack(stack<char> &symbol_stk,
                        stack<ExpressionTreeNode *> &stk, const string &stops) {
  while (!symbol_stk.empty()) {
    int i;
    for (i = 0; i < (int)stops.size(); ++i) {
      if (symbol_stk.top() == stops[i]) break;
    }
    if (i < (int)stops.size()) break;
    ExpressionTreeNode *node =
        new ExpressionTreeNode(string(1, symbol_stk.top()));
    symbol_stk.pop();

    node->right = stk.top();
    stk.pop();
    node->left = stk.top();
    stk.pop();

    stk.push(node);
  }
}

ExpressionTreeNode *build(vector<string> &expression) {
  stack<ExpressionTreeNode *> stk;
  stack<char> symbol_stk;
  for (const auto &token : expression) {
    if (isdigit(token.back()))
      stk.push(new ExpressionTreeNode(token));
    else {
      switch (token.back()) {
        case '(':
          symbol_stk.push(token.back());
          break;
        case ')':
          __pop_symbol_stack(symbol_stk, stk, "(");
          symbol_stk.pop();  // NOTE: '(' should be popped.
          break;
        case '+':
        case '-':
          __pop_symbol_stack(symbol_stk, stk, "(");
          symbol_stk.push(token.back());
          break;
        case '*':
        case '/':
          __pop_symbol_stack(symbol_stk, stk, "(+-");
          symbol_stk.push(token.back());
          break;
      }
    }
  }
  __pop_symbol_stack(symbol_stk, stk, "");
  return stk.empty() ? nullptr : stk.top();
}
