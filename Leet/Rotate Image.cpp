// Redo
void rotate(vector<vector<int> > &matrix) {
  const int N = matrix.size();
  if ( N == 0 ) return;
  for (int i = 0; i <= (N-1)/2; i ++) {
    for (int j = i; j <= N - 2 - i; j ++) {
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[N-1-j][i];
      matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
      matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
      matrix[j][N-1-i] = tmp;
    }
  }
}

