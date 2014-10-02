int largestRectangleArea(vector<int> &height) {
  const int N = height.size();
  if ( N == 0 ) return 0;
  int leftMost[N], rightMost[N];
  int stk[N];
  int stkLen = 0;
  for (int i = 0; i < N; i ++) {
    while ( stkLen > 0 && height[i] <= height[stk[stkLen - 1]] ) stkLen --;
    leftMost[i] = stkLen > 0 ? stk[stkLen - 1] + 1 : 0;
    stk[stkLen ++] = i;
  }
  stkLen = 0;
  for (int i = N - 1; i >= 0; i --) {
    while ( stkLen > 0 && height[i] <= height[stk[stkLen - 1]] ) stkLen --;
    rightMost[i] = stkLen > 0 ? stk[stkLen - 1] - 1 : N - 1;
    stk[stkLen ++] = i;
  }
  int res = 0;
  for (int i = 0; i < N; i ++) {
    res = max(res, height[i] * (rightMost[i] + 1 - leftMost[i]));
  }
  return res;
}

