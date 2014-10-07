// Redo
bool __exist(vector<vector<char>> &board, const string &word, vector<vector<bool>> &visited, int begin, int i, int j) {
  const int L = word.length();
  if ( begin == L ) return true;
  if ( word[begin] != board[i][j] ) return false;
  if ( begin + 1 == L ) return true;

  visited[i][j] = true;
  const int M = board.size();
  const int N = board[0].size();
  if ( i > 0 && !visited[i - 1][j] ) {
    if ( __exist(board, word, visited, begin + 1, i - 1, j) ) return true;
  }
  if ( j > 0 && !visited[i][j - 1] ) {
    if ( __exist(board, word, visited, begin + 1, i, j - 1) ) return true;
  }
  if ( i < M - 1 && !visited[i + 1][j] ) {
    if ( __exist(board, word, visited, begin + 1, i + 1, j) ) return true;
  }
  if ( j < N - 1 && !visited[i][j + 1] ) {
    if ( __exist(board, word, visited, begin + 1, i, j + 1) ) return true;
  }
  visited[i][j] = false;
  return false;
}

bool exist(vector<vector<char> > &board, string word) {
  const int M = board.size();
  const int N = board[0].size();
  vector<vector<bool>> visited(M, vector<bool>(N, false));
  for (int i = 0; i < M; i ++) {
    for (int j = 0; j < N; j ++) {
      if ( __exist(board, word, visited, 0, i, j) ) return true;
    }
  }
  return false;
}

