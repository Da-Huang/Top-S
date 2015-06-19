// #redo
int calculate(string s) {
  const int N = s.size();
  stack<int> nstk;
  stack<char> sstk;
  int begin = 0;
  while (begin <= N) {
    if (begin == N || s[begin] == ')') {
      while (!sstk.empty() && sstk.top() != '(') {
        int v2 = nstk.top();
        nstk.pop();
        if (sstk.top() == '+') nstk.top() = nstk.top() + v2;
        else if (sstk.top() == '-') nstk.top() = nstk.top() - v2;
        sstk.pop();
      }
      if (!sstk.empty()) sstk.pop();
      ++ begin;

    } else if (s[begin] == '+' || s[begin] == '-') {
      if (!sstk.empty() && (sstk.top() == '+' || sstk.top() == '-')) {
        int v2 = nstk.top();
        nstk.pop();
        if (sstk.top() == '+') nstk.top() = nstk.top() + v2;
        else if (sstk.top() == '-') nstk.top() = nstk.top() - v2;
        sstk.pop();
      }
      sstk.push(s[begin]);
      ++ begin;

    } else if (s[begin] == '(') {
      sstk.push('(');
      ++ begin;

    } else if (s[begin] == ' ') {
      ++ begin;

    } else {
      int end = begin + 1;
      while (end < N && isdigit(s[end])) ++ end;
      nstk.push(stoi(s.substr(begin, end - begin)));
      begin = end;
    }
  }
  return nstk.top();
}
