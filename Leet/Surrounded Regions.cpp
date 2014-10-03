// Redo
void dfs(vector<vector<char>> &board, int i, int j) {
  const int M = board.size();
  const int N = board[0].size();
  stack<pair<int, int>> stk;
  stk.push(make_pair(i, j));
  while ( !stk.empty() ) {
    auto p = stk.top();
    stk.pop();
    i = p.first; j = p.second;
    if ( board[i][j] != 'O' ) continue;
    board[i][j] = '#';
    if ( i > 0 ) stk.push(make_pair(i - 1, j));
    if ( j > 0 ) stk.push(make_pair(i, j - 1));
    if ( i < M - 1 ) stk.push(make_pair(i + 1, j));
    if ( j < N - 1 ) stk.push(make_pair(i, j + 1));
  }
}

void solve(vector<vector<char>> &board) {
  const int M = board.size();
  if ( M == 0 ) return;
  const int N = board[0].size();
  if ( N == 0 ) return;
  for (int i = 0; i < M; i ++) {
    dfs(board, i, 0);
    dfs(board, i, N - 1);
  }
  for (int j = 1; j < N - 1; j ++) {
    dfs(board, 0, j);
    dfs(board, M - 1, j);
  }
  for (auto &v : board) {
    for (auto &c : v) {
      if ( c == '#' ) c = 'O';
      else if ( c == 'O' ) c = 'X';
    }
  }
}

