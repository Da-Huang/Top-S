// #redo
int calculate(string s) {
  unordered_map<char, int> priority;
  priority['+'] = priority['-'] = 1;
  priority['*'] = priority['/'] = 2;
  priority['#'] = 0;
  stack<long long> stk;
  stack<char> ops;
  size_t i = 0;
  while (i <= s.size()) {
    if (i == s.size() || s[i] == '+' || s[i] == '-' || s[i] == '*' ||
        s[i] == '/') {
      char op = i == s.size() ? '#' : s[i];
      while (!ops.empty() && priority[ops.top()] >= priority[op]) {
        long long v2 = stk.top();
        stk.pop();
        switch (ops.top()) {
          case '+':
            stk.top() += v2;
            break;
          case '-':
            stk.top() -= v2;
            break;
          case '*':
            stk.top() *= v2;
            break;
          case '/':
            stk.top() /= v2;
            break;
        }
        ops.pop();
      }
      ops.push(op);
      ++i;

    } else if (isdigit(s[i])) {
      size_t j = i + 1;
      while (j < s.size() && isdigit(s[j])) ++j;
      stk.push(stoll(s.substr(i, j - i)));
      i = j;

    } else if (s[i] == ' ') {
      ++i;
    }
  }
  return stk.top();
}

// #version2
void __pop_ops(stack<char> &ops, stack<long long> &operands,
               const string &stops) {
  while (!ops.empty()) {
    size_t i = 0;
    for (; i < stops.size(); ++i) {
      if (ops.top() == stops[i]) break;
    }
    if (i < stops.size()) break;
    long long num = operands.top();
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

int calculate(string s) {
  stack<long long> operands;
  stack<char> ops;
  size_t i = 0;
  while (i < s.size()) {
    switch (s[i]) {
      case '+':
      case '-':
        __pop_ops(ops, operands, "");
        ops.push(s[i]);
        break;
      case '*':
      case '/':
        __pop_ops(ops, operands, "+-");
        ops.push(s[i]);
        break;
      case ' ':
        break;
      default:
        size_t j = i + 1;
        while (j < s.size() && isdigit(s[j])) ++j;
        operands.push(stoll(s.substr(i, j - i)));
        i = j - 1;
    }
    ++i;
  }
  __pop_ops(ops, operands, "");
  return operands.top();
}
