int __maximalSquare(int his[], int N) {
  stack<int> stk;
  int leftMost[N];
  for (int i = 0; i < N; ++ i) {
    while (!stk.empty() && his[stk.top()] >= his[i]) stk.pop();
    leftMost[i] = stk.empty() ? 0 : stk.top() + 1;
    stk.push(i);
  }
  stk = stack<int>();
  int ans = 0;
  for (int i = N - 1; i >= 0; -- i) {
    while (!stk.empty() && his[stk.top()] >= his[i]) stk.pop();
    int rightMost = stk.empty() ? N - 1 : stk.top() - 1;
    stk.push(i);
    int edge = min((rightMost - leftMost[i] + 1), his[i]);
    ans = max(ans, edge * edge);
  }
  return ans;
}

int maximalSquare(vector<vector<char>>& matrix) {
  int ans = 0;
  const int M = matrix.size();
  if (M == 0) return 0;
  const int N = matrix[0].size();
  if (N == 0) return 0;

  int his[N];
  memset(his, 0, sizeof(his));
  for (int i = 0; i < M; ++ i) {
    for (int j = 0; j < N; ++ j) {
      if (matrix[i][j] == '0') his[j] = 0;
      else ++ his[j];
    }
    ans = max(__maximalSquare(his, N), ans);
  }
  return ans;
}
