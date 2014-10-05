// Redo
vector<int> spiralOrder(vector<vector<int> > &matrix) {
  vector<int> res;
  const int M = matrix.size();
  if ( M == 0 ) return res;
  const int N = matrix[0].size();
  if ( N == 0 ) return res;

  int r;
  for (r = 0; r <= (min(M, N) - 1) / 2; r ++) {
    int i, j;
    i = r;
    for (j = r; j <= N - 1 - r; j ++) res.push_back(matrix[i][j]);
    j = N - 1 - r;
    for (i = r + 1; i <= M - 1 - r; i ++) res.push_back(matrix[i][j]);
    if ( r != N - 1 - r && r != M - 1 - r) {
      i = M - 1 - r;
      for (j = N - 2 - r; j > r; j --) res.push_back(matrix[i][j]);
      j = r;
      for (i = M - 1 - r; i > r; i --) res.push_back(matrix[i][j]);
    }
  }
  return res;
}
