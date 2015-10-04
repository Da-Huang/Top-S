void gameOfLife(vector<vector<int>>& board) {
  const int M = board.size();
  if (M == 0) return;
  const int N = board[0].size();
  if (N == 0) return;

  static const int dirs[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      int count = 0;
      for (int k = 0; k < 8; ++k) {
        int ii = i + dirs[k][0];
        int jj = j + dirs[k][1];
        if (ii >= 0 && jj >= 0 && ii < M && jj < N) {
          if (board[ii][jj] & 1) ++count;
        }
      }
      if (count == 3) board[i][j] |= 2;
      else if (count == 2) board[i][j] |= (board[i][j] & 1) << 1;
    }
  }

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      board[i][j] >>= 1;
    }
  }
}
