// Redo
bool isValidSudoku(vector<vector<char> > &board) {
  for (int i = 0; i < 9; i ++) {
    for (int j = 0; j < 9; j ++) {
      if ( board[i][j] == '.' ) continue;
      for (int ii = i + 1; ii < 9; ii ++) {
        if ( board[ii][j] != '.' && board[ii][j] == board[i][j] ) return false;
      }
      for (int jj = j + 1; jj < 9; jj ++) {
        if ( board[i][jj] != '.' && board[i][jj] == board[i][j] ) return false;
      }
      int blocki = i / 3, blockj = j / 3;
      for (int ii = 0; ii < 3; ii ++) {
        for (int jj = 0; jj < 3; jj ++) {
          if ( board[blocki * 3 + ii][blockj * 3 + jj] == '.' ) continue;
          if ( blocki * 3 + ii != i || blockj * 3 + jj != j ) {
            if ( board[blocki * 3 + ii][blockj * 3 + jj] == board[i][j] ) return false;
          }
        }
      }
    }
  }
  return true;
}

