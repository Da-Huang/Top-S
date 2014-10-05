int __his(int his[], int N) {
  int stk[N];
  int stkLen = 0;
  int leftMost[N];
  int rightMost[N];
  leftMost[0] = 0;
  stk[stkLen ++] = 0;
  for (int i = 1; i < N; i ++) {
    while ( stkLen > 0 && his[i] <= his[stk[stkLen - 1]] ) stkLen --;
    if ( stkLen == 0 ) leftMost[i] = 0;
    else leftMost[i] = stk[stkLen - 1] + 1;
    stk[stkLen ++] = i;
  }
  stkLen = 0;
  rightMost[N - 1] = N - 1;
  stk[stkLen ++] = N - 1;
  for (int i = N - 2; i >= 0; i --) {
    while ( stkLen > 0 && his[i] <= his[stk[stkLen - 1]] ) stkLen --;
    if ( stkLen == 0 ) rightMost[i] = N - 1;
    else rightMost[i] = stk[stkLen - 1] - 1;
    stk[stkLen ++] = i;
  }
  int res = 0;
  for (int i = 0; i < N; i ++) {
    res = max(res, his[i] * (rightMost[i] - leftMost[i] + 1));
  }
  return res;
}

int maximalRectangle(vector<vector<char> > &matrix) {
  const int M = matrix.size();
  if ( M == 0 ) return 0;
  const int N = matrix[0].size();
  if ( N == 0 ) return 0;
  int his[N];
  memset(his, 0, sizeof(his));

  int res = 0;
  for (int i = 0; i < M; i ++) {
    for (int j = 0; j < N; j ++) {
      if ( matrix[i][j] == '1' ) his[j] ++;
      else his[j] = 0;
    }
    res = max(res, __his(his, N));
  }
  return res;
}

