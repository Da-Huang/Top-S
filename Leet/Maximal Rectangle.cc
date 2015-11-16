int __maxArea(int h[], int N) {
  int leftMost[N];
  stack<int> stk;
  for (int i = 0; i < N; ++ i) {
    while (!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
    leftMost[i] = stk.empty() ? 0 : stk.top() + 1;
    stk.push(i);
  }
  stk = stack<int>();
  int ans = 0;
  for (int i = N - 1; i >= 0; -- i) {
    while (!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
    int rightMost = stk.empty() ? N - 1 : stk.top() - 1;
    ans = max(ans, (rightMost - leftMost[i] + 1) * h[i]);
    stk.push(i);
  }
  return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
  const int M = matrix.size();
  if (M == 0) return 0;
  const int N = matrix[0].size();
  if (N == 0) return 0;

  int h[N];
  memset(h, 0, sizeof(h));
  int ans = 0;
  for (int i = 0; i < M; ++ i) {
    for (int j = 0; j < N; ++ j) {
      if (matrix[i][j] == '1') ++ h[j];
      else h[j] = 0;
    }
    ans = max(ans, __maxArea(h, N));
  }
  return ans;
}
