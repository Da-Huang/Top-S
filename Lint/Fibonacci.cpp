int fibonacci(int n) {
  int ans[2] = {0, 1};
  for (int i = 2; i < n; ++i) ans[i & 1] += ans[(i - 1) & 1];
  return ans[(n - 1) & 1];
}

// #version2
int fibonacci(int n) {
  if (n == 1) return 0;

  int k = n - 2;
  int helper[2][2] = {{0, 1}, {1, 1}};
  int ans[2][2] = {{1, 0}, {0, 1}};
  int i = 0;
  while (k) {
    if (k & (1 << i)) {
      int next_ans[2][2];
      next_ans[0][0] = ans[0][0] * helper[0][0] + ans[0][1] * helper[1][0];
      next_ans[0][1] = ans[0][0] * helper[0][1] + ans[0][1] * helper[1][1];
      next_ans[1][0] = ans[1][0] * helper[0][0] + ans[1][1] * helper[1][0];
      next_ans[1][1] = ans[1][0] * helper[0][1] + ans[1][1] * helper[1][1];
      memcpy(ans, next_ans, sizeof(ans));
      k &= ~(1 << i);
    }
    int next_helper[2][2];
    next_helper[0][0] =
        helper[0][0] * helper[0][0] + helper[0][1] * helper[1][0];
    next_helper[0][1] =
        helper[0][0] * helper[0][1] + helper[0][1] * helper[1][1];
    next_helper[1][0] =
        helper[1][0] * helper[0][0] + helper[1][1] * helper[1][0];
    next_helper[1][1] =
        helper[1][0] * helper[0][1] + helper[1][1] * helper[1][1];
    memcpy(helper, next_helper, sizeof(helper));
    ++i;
  }
  return ans[1][1];
}
