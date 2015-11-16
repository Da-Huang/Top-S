bool isValid(string s) {
  stack<char> stk;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') stk.push(c);
    else if (c == ')') {
      if (stk.empty() || stk.top() != '(') return false;
      stk.pop();
    } else if (c == ']') {
      if (stk.empty() || stk.top() != '[') return false;
      stk.pop();
    } else { // c == '}'
      if (stk.empty() || stk.top() != '{') return false;
      stk.pop();
    }
  }
  return stk.empty();
}
