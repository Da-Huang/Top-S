vector<vector<int> > generateMatrix(int n) {
  vector<vector<int>> res(n, vector<int>(n));
  if ( n == 0 ) return res;
  int k = 1;
  int r;
  for (r = 0; r < n / 2; r ++) {
    int i, j;
    i = r;
    for (j = r; j < n - 1 - r; j ++) res[i][j] = k ++;
    j = n - 1 - r;
    for (i = r; i < n - 1 - r; i ++) res[i][j] = k ++;
    i = n - 1 - r;
    for (j = n - 1 - r; j > r; j --) res[i][j] = k ++;
    j = r;
    for (i = n - 1 - r; i > r; i --) res[i][j] = k ++;
  }
  if ( n & 1 ) res[r][r] = k;
}
