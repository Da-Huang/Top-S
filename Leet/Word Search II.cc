// #redo
struct TrieNode {
  TrieNode *sub[26];
  bool isEnd = false;
  TrieNode() {
    memset(sub, 0, sizeof(sub));
  }
  ~TrieNode() {
    for (TrieNode *child : sub) {
      delete child;
    }
  }
};

void __findWords(vector<vector<char>> &board, vector<vector<bool>> &visited, size_t i, size_t j, TrieNode *ptr, string &v, unordered_set<string> &ans) {
  if (visited[i][j]) return;

  char c = board[i][j];
  ptr = ptr->sub[c-'a'];
  if (ptr == NULL) return;

  visited[i][j] = true;
  v.push_back(c);
  if (ptr->isEnd) ans.insert(v);

  if (i > 0) __findWords(board, visited, i-1, j, ptr, v, ans);
  if (j > 0) __findWords(board, visited, i, j-1, ptr, v, ans);
  if (i+1 < board.size()) __findWords(board, visited, i+1, j, ptr, v, ans);
  if (j+1 < board[0].size()) __findWords(board, visited, i, j+1, ptr, v, ans);

  v.pop_back();
  visited[i][j] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  TrieNode ROOT;
  for (string &word : words) {
    TrieNode *ptr = &ROOT;
    for (char c : word) {
      if (ptr->sub[c-'a'] == NULL) ptr->sub[c-'a'] = new TrieNode();
      ptr = ptr->sub[c-'a'];
    }
    ptr->isEnd = true;
  }

  unordered_set<string> ans;
  if (board.size() == 0 || board[0].size() == 0) return {};

  vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
  string v;
  for (size_t i = 0; i < board.size(); ++ i) {
    for (size_t j = 0; j < board[0].size(); ++ j) {
      __findWords(board, visited, i, j, &ROOT, v, ans);
    }
  }
  return vector<string>(ans.begin(), ans.end());
}
