void __popOps(stack<char> &ops, stack<int> &operands, const string &stops) {
  while (!ops.empty()) {
    int i;
    for (i = 0; i < (int)stops.size(); ++i) {
      if (ops.top() == stops[i]) break;
    }
    if (i < (int)stops.size()) break;
    int num = operands.top();
    operands.pop();
    switch (ops.top()) {
      case '+':
        operands.top() += num;
        break;
      case '-':
        operands.top() -= num;
        break;
      case '*':
        operands.top() *= num;
        break;
      case '/':
        operands.top() /= num;
        break;
    }
    ops.pop();
  }
}

int evaluateExpression(vector<string> &expression) {
  stack<int> operands;
  stack<char> ops;
  for (const auto &token : expression) {
    switch (token.back()) {
      case '(':
        ops.push(token.back());
        break;
      case ')':
        __popOps(ops, operands, "(");
        ops.pop();
        break;
      case '+':
      case '-':
        __popOps(ops, operands, "(");
        ops.push(token.back());
        break;
      case '*':
      case '/':
        __popOps(ops, operands, "(+-");
        ops.push(token.back());
        break;
      default:
        operands.push(stoi(token));
    }
  }
  __popOps(ops, operands, "");
  return operands.empty() ? 0 : operands.top();
}
