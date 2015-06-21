bool __exist(vector<vector<char>>& board, string &word, vector<vector<bool>> &visited, int i, int j, int k) {
  if (k == (int) word.size()) return true;
  if (i < 0 || i >= (int) board.size()) return false;
  if (j < 0 || j >= (int) board[0].size()) return false;
  if (visited[i][j]) return false;
  if (board[i][j] != word[k]) return false;
  visited[i][j] = true;
  if (
      __exist(board, word, visited, i - 1, j, k + 1) ||
      __exist(board, word, visited, i, j - 1, k + 1) ||
      __exist(board, word, visited, i + 1, j, k + 1) ||
      __exist(board, word, visited, i, j + 1, k + 1)) return true;
  visited[i][j] = false;
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  if (word.size() == 0) return true;
  const int M = board.size();
  if (M == 0) return false;
  const int N = board[0].size();
  if (N == 0) return false;

  vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
  for (int i = 0; i < M; ++ i) {
    for (int j = 0; j < N; ++ j) {
      if (__exist(board, word, visited, i, j, 0)) return true;
    }
  }
  return false;
}
