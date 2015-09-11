// #redo
int calculate(string s) {
  stack<int> vals;
  stack<char> ops;
  size_t begin = 0;
  while (begin <= s.size()) {
    if (begin == s.size() || s[begin] == '+' || s[begin] == '-' ||
        s[begin] == ')') {
      while (!ops.empty()) {
        if (ops.top() == '(') {
          if (begin < s.size() && s[begin] == ')') ops.pop();
          break;
        }

        int v2 = vals.top();
        vals.pop();
        switch (ops.top()) {
          case '+':
            vals.top() += v2;
            break;
          case '-':
            vals.top() -= v2;
            break;
        }
        ops.pop();
      }

      if (begin < s.size() && (s[begin] == '+' || s[begin] == '-'))
        ops.push(s[begin]);
      ++begin;

    } else if (isdigit(s[begin])) {
      int end = begin + 1;
      while (end < s.size() && isdigit(s[end])) ++end;
      vals.push(stoi(s.substr(begin, end - begin)));
      begin = end;

    } else if (s[begin] == '(') {
      ops.push(s[begin++]);

    } else
      ++begin;
  }
  return vals.top();
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
      case '(':
        ops.push(s[i]);
        break;
      case ')':
        __pop_ops(ops, operands, "(");
        ops.pop();
        break;
      case '+':
      case '-':
        __pop_ops(ops, operands, "(");
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
