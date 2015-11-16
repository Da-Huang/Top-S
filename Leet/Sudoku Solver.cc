// redo
bool __solveSudoku(vector<vector<char>>& board, int k) {
  const int N = 9;
  if (k == N * N) return true;
  int row = k / N;
  int col = k % N;
  if (board[row][col] != '.') return __solveSudoku(board, k + 1);

  vector<bool> v(N, true);
  for (int i = 0; i < N; ++ i) {
    if (board[i][col] != '.') v[board[i][col] - '1'] = false;
  }
  for (int j = 0; j < N; ++ j) {
    if (board[row][j] != '.') v[board[row][j] - '1'] = false;
  }
  for (int i = 0; i < N / 3; ++ i) {
    for (int j = 0; j < N / 3; ++ j) {
      char c = board[row-row%3+i][col-col%3+j];
      if (c != '.') v[c - '1'] = false;
    }
  }
  for (int i = 0; i < N; ++ i) {
    if (v[i]) {
      board[row][col] = i + '1';
      if (__solveSudoku(board, k + 1)) return true;
    }
  }
  board[row][col] = '.';
  return false;
}

void solveSudoku(vector<vector<char>>& board) {
  __solveSudoku(board, 0);
}
