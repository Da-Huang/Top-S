// Redo
bool __exist(vector<vector<char> > &board, const string &word, vector<vector<bool>> &visited, int i, int j, int start=0) {
  const int M = board.size();
  const int N = board[0].size();
  const int L = word.length();
  if ( start == L ) return true;

  if ( board[i][j] == word[start] ) {
    if ( start + 1 == L ) return true;
    visited[i][j] = true;
    if ( i > 0 && !visited[i - 1][j] ) {
      if ( __exist(board, word, visited, i - 1, j, start + 1) ) {
        visited[i][j] = false;
        return true;
      }
    }
    if ( j > 0 && !visited[i][j - 1] ) {
      if ( __exist(board, word, visited, i, j - 1, start + 1) ) {
        visited[i][j] = false;
        return true;
      }
    }
    if ( i < M - 1 && !visited[i + 1][j] ) {
      if ( __exist(board, word, visited, i + 1, j, start + 1) ) {
        visited[i][j] = false;
        return true;
      }
    }
    if ( j < N - 1 && !visited[i][j + 1] ) {
      if ( __exist(board, word, visited, i, j + 1, start + 1) ) {
        visited[i][j] = false;
        return true;
      }
    }
    visited[i][j] = false;
  }
  return false;
}

bool exist(vector<vector<char> > &board, string word) {
  const int L = word.length();
  if ( L == 0 ) return true;
  const int M = board.size();
  if ( M == 0 ) return false;
  const int N = board[0].size();
  if ( N == 0 ) return false;
  vector<vector<bool>> visited(M, vector<bool>(N, false));

  for (int i = 0; i < M; i ++) {
    for (int j = 0; j < N; j ++) {
      if ( __exist(board, word, visited, i, j) ) return true;
    }
  }
  return false;
}

