// #redo
int evalRPN(vector<string>& tokens) {
  stack<int> stk;
  for (string &token : tokens) {
    if (isdigit(token.back())) stk.push(stoi(token));
    else {
      int b = stk.top();
      stk.pop();
      int a = stk.top();
      stk.pop();
      switch (token.front()) {
        case '+': stk.push(a + b); break;
        case '-': stk.push(a - b); break;
        case '*': stk.push(a * b); break;
        case '/': stk.push(a / b); break;
      }
    }
  }
  return stk.top();
}
