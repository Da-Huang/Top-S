// #redo
// NOTE: Similar with but has many differences from RPN.
void __popOps(stack<char> &ops, vector<string> &ans, const string &stops) {
  while (!ops.empty()) {
    int i;
    for (i = 0; i < (int)stops.size(); ++i) {
      if (stops[i] == ops.top()) break;
    }
    if (i < (int)stops.size()) break;
    ans.push_back(string(1, ops.top()));
    ops.pop();
  }
}

vector<string> convertToPN(vector<string> &expression) {
  vector<string> ans;
  stack<char> ops;
  for (int i = (int)expression.size() - 1; i >= 0; --i) {
    char last_char = expression[i].back();
    switch (last_char) {
      case ')':
        ops.push(last_char);
        break;
      case '(':
        __popOps(ops, ans, ")");
        ops.pop();
        break;
      case '+':
      case '-':
        __popOps(ops, ans, ")+-");
        ops.push(last_char);
        break;
      case '*':
      case '/':
        __popOps(ops, ans, ")+-*/");
        ops.push(last_char);
        break;
      default:
        ans.push_back(expression[i]);
    }
  }
  __popOps(ops, ans, "");
  reverse(ans.begin(), ans.end());
  return ans;
}
