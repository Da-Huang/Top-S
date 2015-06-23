// #redo
int calculate(string s) {
  stack<int> vals;
  stack<char> ops;
  size_t begin = 0;
  while (begin <= s.size()) {
    if (begin == s.size() || s[begin] == '+' || s[begin] == '-' || s[begin] == ')') {
      while (!ops.empty()) {
        if (ops.top() == '(') {
          if (begin < s.size() && s[begin] == ')') ops.pop();
          break;
        }

        int v2 = vals.top();
        vals.pop();
        switch (ops.top()) {
          case '+': vals.top() += v2; break;
          case '-': vals.top() -= v2; break;
        }
        ops.pop();
      }

      if (begin < s.size() && (s[begin] == '+' || s[begin] == '-')) ops.push(s[begin]);
      ++ begin;

    } else if (isdigit(s[begin])) {
      int end = begin + 1;
      while (end < s.size() && isdigit(s[end])) ++ end;
      vals.push(stoi(s.substr(begin, end - begin)));
      begin = end;

    } else if (s[begin] == '(') {
      ops.push(s[begin ++]);

    } else ++ begin;
  }
  return vals.top();
}
