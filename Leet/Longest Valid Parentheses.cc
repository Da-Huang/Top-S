// #redo
int longestValidParentheses(string s) {
  const int N = s.size();

  stack<int> stk;
  int ans = 0;
  int begin = 0;
  for (int i = 0; i < N; ++ i) {
    if (s[i] == '(') stk.push(i);
    else if (stk.empty()) begin = i + 1;
    else {
      stk.pop();
      int base = stk.empty() ? begin : stk.top() + 1;
      ans = max(ans, i - base + 1);
    }
  }
  return ans;
}
