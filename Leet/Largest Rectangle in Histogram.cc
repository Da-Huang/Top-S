int largestRectangleArea(vector<int>& height) {
  const int N = height.size();
  int leftMost[N];
  stack<int> stk;
  for (int i = 0; i < N; ++ i) {
    while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
    leftMost[i] = stk.empty() ? 0 : stk.top() + 1;
    stk.push(i);
  }
  stk = stack<int>();
  int ans = 0;
  for (int i = N - 1; i >= 0; -- i) {
    while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
    int rightMost = stk.empty() ? N - 1 : stk.top() - 1;
    ans = max(ans, (rightMost - leftMost[i] + 1) * height[i]);
    stk.push(i);
  }
  return ans;
}
