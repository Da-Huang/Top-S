int evalRPN(vector<string>& tokens) {
  stack<int> stk;
  for (const string& token : tokens) {
    if (isdigit(token.back()))
      stk.push(stoi(token));
    else {
      int num = stk.top();
      stk.pop();
      switch (token.back()) {
        case '+':
          stk.top() += num;
          break;
        case '-':
          stk.top() -= num;
          break;
        case '*':
          stk.top() *= num;
          break;
        case '/':
          stk.top() /= num;
          break;
      }
    }
  }
  return stk.top();
}
