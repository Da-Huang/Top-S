bool __partition(string &s, int i, vector<vector<bool>> &isPalin, vector<bool> &able, vector<string> &v, vector<vector<string>> &ans) {
  if (i == (int) s.size()) {
    ans.push_back(v);
    return true;
  }
  if (!able[i]) return false;

  bool mayAble = false;
  for (int j = i; j < (int) s.size(); ++ j) {
    if (isPalin[i][j]) {
      v.push_back(s.substr(i, j + 1 - i));
      mayAble |= __partition(s, j + 1, isPalin, able, v, ans);
      v.pop_back();
    }
  }
  return able[i] = mayAble;
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> ans;
  const int N = s.size();
  if (N == 0) return ans;
  vector<vector<bool>> isPalin(N, vector<bool>(N));
  isPalin[N-1][N-1] = true;
  for (int i = N - 2; i >= 0; -- i) {
    isPalin[i][i] = true;
    isPalin[i][i+1] = s[i] == s[i+1];
    for (int j = i + 2; j < N; ++ j) {
      isPalin[i][j] = isPalin[i+1][j-1] && s[i] == s[j];
    }
  }
  vector<string> v;
  vector<bool> able(N, true);
  __partition(s, 0, isPalin, able, v, ans);
  return ans;
}
