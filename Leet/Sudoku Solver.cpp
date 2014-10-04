// Redo
short __able(vector<vector<char>> &board, int row, int col) {
  // board[row][col] must be '.'
  short res = 0xFFFF;
  for (int i = 0; i < 9; i ++) {
    if ( board[i][col] == '.' ) continue;
    int d = board[i][col] - '0';
    res &= ~(1 << d);
  }
  for (int j = 0; j < 9; j ++) {
    if ( board[row][j] == '.' ) continue;
    int d = board[row][j] - '0';
    res &= ~(1 << d);
  }
  const int ROW = row / 3;
  const int COL = col / 3;
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      const int ii = ROW * 3 + i;
      const int jj = COL * 3 + j;
      if ( board[ii][jj] == '.' ) continue;
      int d = board[ii][jj] - '0';
      res &= ~(1 << d);
    }
  }
  return res;
}

bool __solveSudoku(vector<vector<char>> &board, int start=0) {
  if ( start == 81 ) return true;
  int i = start / 9;
  int j = start % 9;
  if ( board[i][j] != '.' ) return __solveSudoku(board, start + 1);
  short able = __able(board, i, j);
  for (int k = 1; k <= 9; k ++) {
    if ( able & (1 << k) ) {
      board[i][j] = k + '0';
      if ( __solveSudoku(board, start + 1) ) return true;
    }
  }
  board[i][j] = '.';
  return false;
}

void solveSudoku(vector<vector<char> > &board) {
  __solveSudoku(board, 0);
}

