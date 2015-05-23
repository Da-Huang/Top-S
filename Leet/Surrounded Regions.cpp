// #redo
void __solve(vector<vector<char>> &board, int M, int N, int i, int j) {
  stack<pair<int, int>> stk;
  stk.push(make_pair(i, j));
  while (!stk.empty()) {
    auto p = stk.top();
    stk.pop();
    if (board[p.first][p.second] != 'O') continue;
    board[p.first][p.second] = 'T';
    if (p.first > 0) stk.push(make_pair(p.first-1, p.second));
    if (p.second > 0) stk.push(make_pair(p.first, p.second-1));
    if (p.first+1 < M) stk.push(make_pair(p.first+1, p.second));
    if (p.second+1 < N) stk.push(make_pair(p.first, p.second+1));
  }
}

void solve(vector<vector<char>>& board) {
  const int M = board.size();
  if (M == 0) return;
  const int N = board[0].size();
  if (N == 0) return;

  for (int i = 0; i < M; ++ i) {
    __solve(board, M, N, i, 0);
    __solve(board, M, N, i, N-1);
  }
  for (int j = 0; j < N; ++ j) {
    __solve(board, M, N, 0, j);
    __solve(board, M, N, M-1, j);
  }
  for (auto &v : board) {
    for (char &c : v) {
      if (c == 'T') c = 'O';
      else if (c == 'O') c = 'X';
    }
  }
}
