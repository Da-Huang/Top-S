void setZeroes(vector<vector<int> > &matrix) {
  const int M = matrix.size();
  if ( M == 0 ) return;
  const int N = matrix[0].size();
  if ( N == 0 ) return;
  bool zeroFirstLine = false;
  for (int j = 0; j < N; j ++) {
    if ( matrix[0][j] == 0 ) {
      zeroFirstLine = true;
      break;
    }
  }
  for (int i = 1; i < M; i ++) {
    bool zeroThisLine = false;
    for (int j = 0; j < N; j ++) {
      if ( matrix[i][j] == 0 ) {
        matrix[0][j] = 0;
        zeroThisLine = true;
      }
    }
    if ( zeroThisLine ) {
      for (int j = 0; j < N; j ++) {
        matrix[i][j] = 0;
      }
    }
  }
  for (int j = 0; j < N; j ++) {
    if ( matrix[0][j] == 0 ) {
      for (int i = 1; i < M; i ++) {
        matrix[i][j] = 0;
      }
    }
  }
  if ( zeroFirstLine ) {
    for (int j = 0; j < N; j ++) {
      matrix[0][j] = 0;
    }
  }
}

