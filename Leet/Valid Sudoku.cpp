// #redo
bool isValidSudoku(vector<vector<char>>& board) {
  const int N = 9;
  for (int i = 0; i < N; ++ i) {
    vector<bool> v1(N, false);
    vector<bool> v2(N, false);
    vector<bool> v3(N, false);
    for (int j = 0; j < N; ++ j) {
      char c = board[i][j];
      if (c != '.') {
        if (v1[c - '0']) return false;
        v1[c - '0'] = true;
      }
      c = board[j][i];
      if (c != '.') {
        if (v2[c - '0']) return false;
        v2[c - '0'] = true;
      }
      c = board[i/3*3+j/3][i%3*3+j%3];
      if (c != '.') {
        if (v3[c - '0']) return false;
        v3[c - '0'] = true;
      }
    }
  }
  return true;
}
